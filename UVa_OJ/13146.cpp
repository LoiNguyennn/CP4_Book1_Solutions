#include <bits/stdc++.h>

using namespace std;

int dp[101][101];

int main() {
    int TC;
    cin >> TC;
    cin.ignore();

    while (TC--) {
        string a, b;
        getline(cin, a);
        getline(cin, b);

        const int INF = 1e9;

        int m = a.size(), n = b.size();
        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int i = 0; i <= n; ++i) dp[0][i] = i;
            
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]);
                dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
            }
        }
        cout << dp[m][n] << endl;
    }   
    return 0;
}