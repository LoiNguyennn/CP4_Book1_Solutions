#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll dp[11];
    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = 1;
    for (int i = 2; i < 11; ++i)
        for (int j = 0; j < i; ++j)
            dp[i] += dp[j] * dp[i - j - 1];

    int n;
    int tc = 0;
    while (cin >> n) {
        if (tc) cout << endl;
        cout << dp[n] << endl;
        ++tc;
    }
    return 0;
}