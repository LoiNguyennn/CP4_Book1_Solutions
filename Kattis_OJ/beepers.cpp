#include <bits/stdc++.h>

#define LSOne(S) ((S) & (-S))

using namespace std;

int dist[21][21], memo[1 << 11][1 << 11];

int dp(int u, int mask) {
    if (mask == 0) return dist[u][0];
    
    int& ans = memo[u][mask];
    if (ans != -1) return ans;
    int m = mask;
    ans = 1e9;
    while (m) {
        int t = LSOne(m);
        int v = log2(t) + 1;
        ans = min(ans, dist[u][v] + dp(v, mask ^ t));
        m -= t;
    }
    return ans;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        memset(memo, -1, sizeof(memo));
        memset(dist, 0, sizeof(dist));

        vector<pair<int, int>> v;
        int x, y;
        cin >> x >> y;
        cin >> x >> y;

        v.push_back({x, y});

        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x >> y;
            v.push_back({x, y});
        }

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j) 
                dist[i][j] = dist[j][i] = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
        
        cout << dp(0, (1 << n) - 1) << endl;    
    }
    return 0;
}