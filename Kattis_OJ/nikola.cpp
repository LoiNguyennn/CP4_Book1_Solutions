#include <bits/stdc++.h>

using namespace std;

int n;
int a[1001];
int dp[1001][10000];

int move(int i, int j) {
	if (i == n) return a[i];
	
	int& ans = dp[i][j];
	if (ans != -1) return ans;
	if (j == 0)
		return ans = move(i + j + 1, j + 1);
	if (i - j >= 1 && i + j + 1 <= n)
		return ans = min(move(i + j + 1, j + 1), move(i - j, j)) + a[i];
	else if (i - j >= 1) 
		return ans = move(i - j, j) + a[i];
	else if (i + j + 1 <= n)
		return ans = move(i + j + 1, j + 1) + a[i];
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i]; 
	cout << move(1, 0) << endl;
	return 0;
}