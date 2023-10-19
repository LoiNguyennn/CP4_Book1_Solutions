#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n && n) {
        pair<int, int> a[n];
        for (int i = 0; i < n; ++i) 
            cin >> a[i].first >> a[i].second;
        sort(a, a + n);

        int dp[n];
        for (int i = 0; i < n; ++i) dp[i] = 1;

        int ans = 1;
        for (int i = 1; i < n; ++i) {
            int max_len = 1;
            for (int j = 0; j < i; ++j) {
                if (a[j].second <= a[i].second)
                    max_len = max(dp[j] + 1, max_len);
            }
            dp[i] = max_len;
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
    cout << "*" << endl;
    return 0;
}