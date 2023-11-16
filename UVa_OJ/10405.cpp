#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[1001][1001];
ll INF = -1e12;

int main() {
    string a, b;
    while (getline(cin, a) && getline(cin, b)) {
        int n = a.size(), m = b.size();
        for (int i = 0; i <= n; ++i) dp[i][0] = 0;
        for (int j = 0; j <= m; ++j) dp[0][j] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i - 1][j - 1] + ((a[i - 1] == b[j - 1]) ? 1 : INF);
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            }
        }

        cout << dp[n][m] << endl;
    }
    return 0;
}