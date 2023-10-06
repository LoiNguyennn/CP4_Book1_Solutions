#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> AL;
vector<int> p;
vector<bool> visited;
int CC_Cost;

void dfs(int u) {
    visited[u] = true;
    CC_Cost += p[u];
    for (int v : AL[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    p.assign(n, 0);

    for (int i = 0; i < n; ++i) cin >> p[i];
    
    AL.resize(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    visited.assign(n, false);
    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        CC_Cost = 0;
        dfs(i);
        if (CC_Cost != 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    cout << "POSSIBLE\n";
    return 0;
}