#include <bits/stdc++.h>

using namespace std;

int dfs_num[1000], dfs_low[1000], dfs_parent[1000];
int counter = 0;
vector<pair<int, int>> weeks;

void dfs(int u, vector<vector<int>>& AL) {
    dfs_num[u] = dfs_low[u] = counter++;
    for (int v : AL[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            dfs(v, AL);
            if (dfs_low[v] > dfs_num[u]) 
                weeks.push_back({min(u, v), max(u, v)});
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (dfs_parent[u] != v) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        memset(dfs_num, -1, sizeof(dfs_num));
        memset(dfs_parent, -1, sizeof(dfs_parent));
        memset(dfs_low, 0, sizeof(dfs_low));
        vector<vector<int>> AL(n);
        weeks.clear();
        counter = 0;
        
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            AL[a].push_back(b);
            AL[b].push_back(a);
        }

        for (int i = 0; i < n; ++i)
            dfs(i, AL);

        sort(weeks.begin(), weeks.end(), cmp);
        cout << weeks.size();
        for (int i = 0; i < weeks.size(); ++i)
            cout << " " << weeks[i].first << " " << weeks[i].second;
        cout << endl;
    }    
    return 0;
}