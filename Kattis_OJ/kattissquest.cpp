#include <bits/stdc++.h>

using namespace std;

int main() {
	map<int, priority_queue<int>> mp;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		if (s == "add") {
			int e, g;
			cin >> e >> g;
			mp[e].push(g);
		} else {
			int x;
			cin >> x;
			unsigned long long gold = 0;
			while (!mp.empty() && x >= mp.begin()->first) {
				auto it = mp.lower_bound(x);
				if (it == mp.end())
					--it;
				while (it != mp.begin() && it->first > x)
					--it;
				gold += it->second.top();
				x -= it->first;
				mp[it->first].pop();
				if (it->second.empty())
					mp.erase(it);
			}
			cout << gold << endl;
		}
	}
	return 0;
}