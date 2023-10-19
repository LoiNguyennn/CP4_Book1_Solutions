#include <bits/stdc++.h>

using namespace std;

int dfs_num[10000], dfs_low[10000], dfs_parent[10000];
int counter = 0;
vector<pair<int, int>> bridges;

void dfs(int u, vector<unordered_set<int>>& AL) {
    dfs_num[u] = dfs_low[u] = ++counter;
    for (int v : AL[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            dfs(v, AL);
            if (dfs_low[v] > dfs_num[u])
                bridges.push_back({u, v});
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (dfs_parent[u] != v) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<unordered_set<int>> AL(n);
    memset(dfs_num, -1, sizeof(dfs_num));


    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        AL[a].insert(b);
        AL[b].insert(a);
    }    

    dfs(0, AL);

    for (auto x : bridges) {
        AL[x.first].erase(x.second);
        AL[x.second].erase(x.first);
    }

    for (int i = 0; i < n; ++i) 
        dfs_num[i] = -1;
    counter = 0;
    dfs(0, AL);
    cout << counter << endl;

    return 0;
}