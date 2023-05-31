#include <bits/stdc++.h>

using namespace std;

int eratos[1121];
vector<int> prime;

void sieve() {
	eratos[0] = eratos[1] = 1;
	for (int i = 2; i * i < 1121; ++i)
		if (!eratos[i])
			for (int j = i * i; j < 1121; j += i) 
				eratos[j] = 1;				
	
	for (int i = 0; i < 1121; ++i) {
		if (!eratos[i])
			prime.push_back(i);
	}
}

int main() {
	int n, k;
	sieve();
	int dp[1121][15];
	memset(dp, 0, sizeof(dp)); 

	dp[0][0] = 1;

	for (int p : prime) {
		for (int i = 1120; i >= p; --i) {
			for (int j = 1; j <= 14; ++j) {
				dp[i][j] += dp[i - p][j - 1];
			}
		}
	}

	while (cin >> n >> k) {
		if (n == 0 && k == 0) break;
		cout << dp[n][k] << endl;
	}
	return 0;
}