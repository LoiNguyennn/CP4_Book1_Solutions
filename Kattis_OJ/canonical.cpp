#include <bits/stdc++.h>

using namespace std;

int gd[100][2000000 + 7];
int n, coin[100];

int greedy(int id, int remV) {
	if (id < 0 || remV <= 0)
		return 0;
	int& ans = gd[id][remV];
	if (ans != -1) return ans;
	if (remV >= coin[id])
		return ans = greedy(id, remV - coin[id]) + 1;
	return ans = greedy(id - 1, remV);
}	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	memset(gd, -1, sizeof(gd));
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> coin[i];

	int s = coin[n - 1] + coin[n - 2];
	int dp[s + 1];
	for (int i = 0; i <= s; ++i) dp[i] = 1e9;
	dp[0] = 0;

	bool flag = false;

	for (int i = 1; i <= s; ++i) {
		for (int j = 0; j < n && coin[j] <= i; ++j) 
			dp[i] = min(dp[i], dp[i - coin[j]] + 1);
		if (dp[i] != greedy(n - 1, i)) {
			flag = true;
			break;
		}
	}

	if (!flag) 
		cout << "canonical\n";
	else 
		cout << "non-canonical\n";
	return 0;
}