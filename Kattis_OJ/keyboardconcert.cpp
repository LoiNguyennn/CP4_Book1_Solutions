#include <bits/stdc++.h>

using namespace std;

int memo[1001][1001];
set<int> can[1001];
vector<int> tune;

const int INF = 1e9;
int n, m;

int dp(int i, int j) {
    if (i >= m) return 0;

    int& ans = memo[i][j];
    if (ans != -1) return ans;

    if (can[tune[i]].count(j))
        return ans = dp(i + 1, j);
    else {
        ans = INT_MAX;
        for (int k : can[tune[i]])
            ans = min(ans, dp(i + 1, k) + 1);
        return ans;
    }
}

int main() {
    cin >> n >> m;
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            can[x].insert(i);
        }
    }

    tune.resize(m);
    for (int i = 0; i < m; ++i) cin >> tune[i];

    int ans = INT_MAX;
    for (int i : can[tune[0]]) {
        ans = min(ans, dp(0, i));
    }
    cout << ans << endl;
    return 0;
}