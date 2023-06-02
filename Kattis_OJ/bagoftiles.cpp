#include <bits/stdc++.h>

using namespace std;

int tile[30];
int m, n, t;

int memo[30][10001][30];
int dp(int id, int remT, int remN) {
	if (remT == 0 && remN == 0)
		return 1;
	if (id == m || remN <= 0 || remT <= 0)
		return 0;
	int& ans = memo[id][remT][remN];
	if (ans != -1) return ans;
	return ans = dp(id + 1, remT - tile[id], remN - 1) + dp(id + 1, remT, remN);
}

int comb[31][31];
int dp_comb(int n, int k) {
	int& ans = comb[n][k];
	if (k == 0 || n == k) return ans = 1;
	if (n < k) return 0;
	if (ans) return ans;
	return ans = dp_comb(n - 1, k - 1) + dp_comb(n - 1, k);
}

int main() {
	int G;
	cin >> G;
	int game_counter = 0;
	while (G--) {
		memset(memo, -1, sizeof(memo));
		cin >> m;
		for (int i = 0; i < m; ++i)
			cin >> tile[i];
		cin >> n >> t;
		int a = dp(0, t, n);
		cout << "Game " << ++game_counter << " -- " << a << " : " << dp_comb(m, n) - a << endl;
	}
	return 0;
}