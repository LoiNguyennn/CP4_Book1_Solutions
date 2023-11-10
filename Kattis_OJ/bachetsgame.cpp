#include <bits/stdc++.h>

using namespace std;

int n, m;
int dp[1000000 + 10];

int main() {
    while (cin >> n >> m) {
        int a[m];
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }

        
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i - a[j] >= 0 && dp[i - a[j]] == 0) 
                    dp[i] = 1;
            }
        }

        if (dp[n]) {
            cout << "Stan wins\n";
        } else {
            cout << "Ollie wins\n";
        }
    }
    return 0;
}