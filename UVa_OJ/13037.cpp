#include <bits/stdc++.h>

using namespace std;

int main() {
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; ++tc) {
		cout << "Case #" << tc << ":\n";
		int n[3];
		unordered_set<int> person[3];
		unordered_set<int> all;
		
		for (int i = 0; i < 3; ++i)
			cin >> n[i];
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < n[i]; ++j) {
				int t;
				cin >> t;
				person[i].insert(t);
				all.insert(t);
			}


		for (int i = 0; i < 3; ++i) {
			int ans1 = 0, ans2 = 0;
			for (auto x : person[i]) {
				int cnt = 0;
				for (int j = 0; j < 3; ++j) {
					if (i != j && person[j].count(x) == 0)
						++cnt;
				}
				if (cnt == 2) ++ans1;
			}
			for (auto x : all) {
				int cnt = 0;
				for (int j = 0; j < 3; ++j)
					if (i != j && person[j].count(x))
						++cnt;
				if (person[i].count(x) == 0 && cnt == 2)
					++ans2;
			}
			cout << ans1 << " " << ans2 << endl;
		}
	}
	return 0;
}