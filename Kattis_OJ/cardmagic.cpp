#include <iostream>
#include <cstring>

#define MOD int(1e9 + 9);

using namespace std;

int memo[100][5000];
int n, k, t;

int dp(int pos, int left) {
	if (left == 0 && pos == n)
		return 1;
	if (left < 0 || pos == n) 
		return 0;

	int& ans = memo[pos][left];
	if (ans != -1)
		return ans;

	ans = 0;
	for (int i = 1; i <= k; ++i) {
		ans += dp(pos + 1, left - i);
		ans %= MOD;
	}
	
	return ans;
}

int main() {
	cin >> n >> k >> t;
	memset(memo, -1, sizeof(memo));
	cout << dp(0, t) << endl;
	return 0;
}