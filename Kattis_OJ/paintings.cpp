#include <bits/stdc++.h>

using namespace std;

unordered_map<string, unordered_set<string>> mp;
vector<string> colors;
vector<string> X;
vector<string> ans;
int cnt = 0;

void backtrack(int n, bool used[]) {
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			if (mp[*X.rbegin()].find(colors[i]) != mp[*X.rbegin()].end())
				continue;
			X.push_back(colors[i]);
			used[i] = true;
			if (X.size() > n) {
				++cnt;
				if (cnt == 1)
					ans = X;
			} else {
				backtrack(n, used);
			}
			X.pop_back();
			used[i] = false;
		}
	}
}

int main() {
	int TC;
	cin >> TC;
	while (TC--) {	
		int n;
		cin >> n;
		colors.push_back("0");
		X.push_back("0");
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			colors.push_back(s);
		}
		int t;
		cin >> t;
		for (int i = 0; i < t; ++i) {
			string s1, s2;
			cin >> s1 >> s2;
			mp[s1].insert(s2);
			mp[s2].insert(s1);
		}
		bool used[n + 1];
		memset(used, 0, sizeof(used));
		backtrack(n, used);
		cout << cnt << endl;
		for (int i = 1; i < ans.size(); ++i)
			cout << ans[i] << " ";
		cout << endl;

		mp.clear();
		colors.clear();
		X.clear();
		ans.clear();
		cnt = 0;
	}
	return 0;
}