#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> to_id;
unordered_map<int, string> to_name;
vector<vector<int>> AL;
vector<int> dfs_num, dfs_low, dfs_parent;
vector<bool> isAP;
int dfsRoot, dfsCount, rootChild;

void dfs(int u) {
    dfs_num[u] = dfs_low[u] = dfsCount++;
    for (int v : AL[u]) {
        if (dfs_num[v] == -1) {
            if (u == dfsRoot) ++rootChild;
            dfs_parent[v] = u;
            dfs(v);
            if (dfs_low[v] >= dfs_num[u]) {
                isAP[u] = true;
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (dfs_parent[u] != v) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}

int main() {
    int n;
    int tc = 1;
    while (cin >> n) {
        if (n == 0) break;
        if (tc > 1) cout << endl;
        AL.assign(n, vector<int>());
        dfs_num.assign(n, -1);
        dfs_low.assign(n, -1);
        dfs_parent.assign(n, -1);
        isAP.assign(n, false);
        to_name.clear();
        to_id.clear();
        dfsCount = 0;


        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            to_id[s] = i;
            to_name[i] = s;
        }

        int r;
        cin >> r;
        for (int i = 0; i < r; ++i) {
            string u, v;
            cin >> u >> v;
            AL[to_id[u]].push_back(to_id[v]);
            AL[to_id[v]].push_back(to_id[u]);
        }

        for (int i = 0; i < n; ++i) {
            if (dfs_num[i] == -1) {
                dfsRoot = i;
                rootChild = 0;
                dfs(i);
                isAP[i] = rootChild > 1;
            }
        }
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            if (isAP[i]) {
                ans.push_back(to_name[i]);
            }
        }
        sort(ans.begin(), ans.end());
        cout << "City map #" << tc++ << ": " << ans.size() << " camera(s) found\n";
        for (string x : ans)
            cout << x << endl;
    }
    return 0;
}
