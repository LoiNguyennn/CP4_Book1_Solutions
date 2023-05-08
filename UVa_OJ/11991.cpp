#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m) {
		int a[n + 1];
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		vector<map<int, int>> AL(n + 1);
		map<int, int> oc;
		for (int i = 1; i <= n; ++i) {
			++oc[a[i]];
			AL[oc[a[i]]].insert({a[i], i});
		}
		for (int i = 0; i < m; ++i) {
			int k, v;
			cin >> k >> v;
			auto it = AL[k].find(v);
			if (it == AL[k].end())
				cout << "0\n";
			else cout << it->second << endl;
		}
	}
	return 0;
}