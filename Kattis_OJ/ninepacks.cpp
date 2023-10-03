#include <bits/stdc++.h>

#define INF (int)1e9

using namespace std;

vector<int> H, B;
int memo[111][111][2023];

// diff = h - b + 1000(offset)
int dp(int h, int b, int diff) {
    if (diff == 1000) return 0;
    if (diff < 1000 && h >= H.size()) return INF;
    if (diff > 1000 && b >= B.size()) return INF;
    int &ans = memo[h][b][diff];
    if (ans != -1) return ans;
    if (diff < 1000) { // h < b => take more hotdogs   
        return ans = min(dp(h + 1, b, diff + H[h]) + 1, dp(h + 1, b, diff));
    } else {
        return ans = min(dp(h, b + 1, diff - B[b]) + 1, dp(h, b + 1, diff));
    }
}

int main() {
    memset(memo, -1, sizeof(memo));

    int m;
    cin >> m;
    H.assign(m, 0);
    for (int i = 0; i < m; ++i) cin >> H[i];
    
    int n;
    cin >> n;
    B.assign(n, 0);
    for (int i = 0; i < n; ++i) cin >> B[i];

    int ans = INF;
    for (int i = 0; i < H.size(); ++i) {
        ans = min(ans, 1 + dp(i + 1, 0, 1000 + H[i]));
    }   
    if (ans == INF) cout << "impossible\n";
    else cout << ans << endl;
    return 0;
}