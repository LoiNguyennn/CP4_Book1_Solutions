#include <bits/stdc++.h>

using namespace std;

int memo[25][205];

int backtrack(const vector<vector<int>>& price, int b, int g, int M, int C, bool& possible) {
	if (memo[g][b])
		return memo[g][b];
	if (g == C) {
		possible = true;
		return memo[g][b] = M - b;
	}	
	int val = INT_MIN;
	for (int j = 0; j < price[g].size(); ++j) {
		if (b >= price[g][j])
			val = max(val, backtrack(price, b - price[g][j], g + 1, M, C, possible));		
	}
	return memo[g][b] = val;
}

int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		int M, C;
		cin >> M >> C;
		vector<vector<int>> price(C);
		for (int i = 0; i < C; ++i) {
			int k;
			cin >> k;
			for (int j = 0; j < k; ++j) {
				int t;
				cin >> t;
				price[i].push_back(t);
			}
		}
		bool possible = false;
		int ans = backtrack(price, M, 0, M, C, possible);
		if (possible) {
			cout << ans << endl;
		} else {
			cout << "no solution\n";
		}
		memset(memo, 0, sizeof(memo));
	}
	return 0;
}