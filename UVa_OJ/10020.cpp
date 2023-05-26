#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		int M, l, r;
		cin >> M;
		vector<pair<int, int>> segment;
		while (cin >> l >> r) {
			if (l == 0 && r == 0) break;
			segment.push_back({l, r});	
		}
		int n = segment.size();

		sort(segment.begin(), segment.end());
		int covered = 0;
		bool possible = true;
		int ans = 0;
		vector<pair<int, int>> res;

		for (int i = 0; i < n; ++i) {
			if (segment[i].second > covered) {
				if (segment[i].first > covered) {
					possible = false;
					break;
				}
				int max_range = INT_MIN;
				int idx;
				for (int j = i; (j < n) && (segment[j].first <= covered); ++j) {
					if (segment[j].second > max_range) {
						max_range = segment[j].second;
						idx = j;
					}
				}
				covered = max_range;
				i = idx;
				res.push_back(segment[idx]);
				++ans;
				if (covered >= M) 
					break;
			}
		}

		if (!possible || covered < M)
			cout << "0\n";
		else {
			cout << ans << endl;
			for (int i = 0; i < res.size(); ++i)
				cout << res[i].first << " " << res[i].second << '\n';			
		}
		if (TC)
			cout << '\n';
	}	
	return 0;
}