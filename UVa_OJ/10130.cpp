#include <bits/stdc++.h>

using namespace std;

int memo[1001][31];
int p[1001], w[1001];
int n, S;

int dp(int id, int remW) {
    if (id >= n || remW == 0)
        return 0;
    if (memo[id][remW])
        return memo[id][remW];
    if (remW < w[id])
        return memo[id][remW] = dp(id + 1, remW);
    return max(dp(id + 1, remW), dp(id + 1, remW - w[id]) + p[id]);
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n;
        for (int i = 0; i < n; ++i) 
            cin >> p[i] >> w[i];

        int m;
        cin >> m;
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            cin >> S;
            ans += dp(0, S);
            memset(memo, 0, sizeof(memo));
        }
        memset(p, 0, sizeof(p));
        memset(w, 0, sizeof(w));
        cout << ans << endl;
    }
    return 0;
}