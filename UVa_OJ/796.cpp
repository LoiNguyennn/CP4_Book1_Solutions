#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> AL;
vector<int> dfs_num, dfs_low, dfs_parent;
set<pair<int, int>> ans;
int dfsCount;

void dfs(int u) {
    dfs_num[u] = dfs_low[u] = dfsCount++;
    for (int v : AL[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            dfs(v);
            if (dfs_low[v] > dfs_num[u]) {
                int tmp1 = u, tmp2 = v;
                if (tmp1 > tmp2) swap(tmp1, tmp2);
                ans.insert({tmp1, tmp2});
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    int n;
    while (cin >> n) {
        cin.ignore();

        AL.assign(n, vector<int>());
        dfsCount = 0;
        dfs_num.assign(n, -1);
        dfs_low.assign(n, -1);
        dfs_parent.assign(n, -1);
        ans.clear();

        for (int i = 0; i < n; ++i) {
            string s;
            getline(cin, s);
            stringstream sin(s);

            int u;
            sin >> u;
            string gar;
            sin >> gar;

            int v;
            while (sin >> v) {
                AL[u].push_back(v);
                AL[v].push_back(u);
            }
        }

        for (int i = 0; i < n; ++i) {
            if (dfs_num[i] == -1)
                dfs(i);
        }
        cout << ans.size() << " critical links\n";
        for (auto it : ans) {
            cout << it.first << " - " << it.second << endl;
        }
        cout << endl;
    }
    return 0;
}
