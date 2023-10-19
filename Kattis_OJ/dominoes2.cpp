#include <bits/stdc++.h>

using namespace std;

bool visited[10000];

void dfs(const vector<vector<int>>& AL, int u) {
    visited[u] = true;
    for (int v : AL[u]) {
        if (!visited[v])
            dfs(AL, v);
    }
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        memset(visited, false, sizeof(visited));
        int n, m, l;
        cin >> n >> m >> l;
        vector<vector<int>> AL(n);
        for (int i = 0; i < m; ++i) {
            int x, y;
            cin >> x >> y;
            AL[x - 1].push_back(y - 1);
        }

        for (int i = 0; i < l; ++i) {
            int u;
            cin >> u;
            dfs(AL, u - 1);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i)
            if (visited[i])
                ++ans;
        cout << ans << endl;
    }
    return 0;
}