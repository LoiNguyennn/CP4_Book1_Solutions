#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

vector<int> dist1, dist2;

vector<vector<int>> bfs(vector<vector<int>>& AL, int s1, int s2) {
    vector<vector<int>> tree(AL.size());
    queue<int> q;
    q.push(s1);
    q.push(s2);
    dist1[s1] = dist1[s2] = 0;
    tree[s1].push_back(s2);
    tree[s2].push_back(s1);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : AL[u]) {
            if (dist1[v] == INF) {
                dist1[v] = dist1[u] + 1;
                q.push(v);
                tree[u].push_back(v);
                tree[v].push_back(u);
            }
        }
    }
    return tree;
}

int getDiameter(vector<vector<int>> tree) {
    int max_dist = 0, max_dist_vertex = 0;
    for (int i = 0; i < tree.size(); ++i) {
        if (dist1[i] > max_dist) {
            max_dist = dist1[i];
            max_dist_vertex = i;
        }
    }

    queue<int> q;
    q.push(max_dist_vertex);
    dist2[max_dist_vertex] = 0;
    int diameter = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : tree[u]) {
            if (dist2[v] == INF) {
                q.push(v);
                dist2[v] = dist2[u] + 1;
                diameter = max(diameter, dist2[v]);
            }
        }
    }
    return diameter;
}

int main() {
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {
        cout << "Case #" << tc << ":\n";

        int n, m;
        cin >> n >> m;    

        vector<vector<int>> AL(n);
        vector<pair<int, int>> EL;
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            AL[u].push_back(v);
            AL[v].push_back(u);
            EL.push_back({u, v});
        }
        int res = INF;
        for (int i = 0; i < m; ++i) {
            dist1.assign(n, INF);
            dist2.assign(n, INF);

            vector<vector<int>> tree = bfs(AL, EL[i].first, EL[i].second);    
            res = min(res, getDiameter(tree));
        }
        cout << res << endl;
        cout << endl;
    }
    return 0;
}