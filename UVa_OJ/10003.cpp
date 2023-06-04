#include <bits/stdc++.h>

using namespace std;

int memo[1000][1000], a[60];

int dp(int left, int right) {
	if (right - left == 1) return 0;
	int& ans = memo[left][right];
	if (ans != -1) return ans;
	ans = 1e9;
	for (int i = left + 1; i < right; ++i) 
		ans = min(ans, dp(left, i) + dp(i, right) + a[right] - a[left]);
	return ans;
}

int main() {
	int leng;
	while (cin >> leng && leng) {
		memset(memo, -1, sizeof(memo));
		int n;
		cin >> n;
		a[0] = 0;
		for (int i = 1; i <= n; ++i)
			cin >> a[i];
		a[n + 1] = leng;
		cout << "The minimum cutting is " << dp(0, n + 1) << "." << endl;
	}
	return 0;
}