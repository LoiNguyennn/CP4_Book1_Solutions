#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

vector<vector<int>> AL;
vector<int> dist, parent, tree_id;
int diameter, farthest_node, id = 0;


void bfs(int s) {
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : AL[u]) {
            if (tree_id[v] != tree_id[u]) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                tree_id[v] = tree_id[u];
                q.push(v);
                if (dist[v] > diameter) {
                    diameter = dist[v];
                    farthest_node = v;
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    AL.resize(n);

    vector<pair<int, int>> tree;
    
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }    

    dist.assign(n, 0);
    parent.assign(n, -1);
    tree_id.assign(n, -1);

    for (int i = 0; i < n; ++i) {
        if (tree_id[i] != -1) continue;
        diameter = 0, farthest_node = i;
        tree_id[i] = id++;
        bfs(i);

        diameter = 0;
        tree_id[farthest_node] = id++;
        bfs(farthest_node);
        


        int center = farthest_node;
        while (dist[center] > diameter / 2)
            center = parent[center];
        tree.push_back({diameter, center});
    }

    sort(tree.begin(), tree.end(), greater<ii>());

    for (int i = 1; i < tree.size(); ++i) {
        AL[tree[0].second].push_back(tree[i].second);
        AL[tree[i].second].push_back(tree[0].second);
    }

    diameter = 0, farthest_node = tree[0].second;
    tree_id[tree[0].second] = id++;
    bfs(tree[0].second);

    diameter = 0;
    tree_id[farthest_node] = id++;
    bfs(farthest_node);

    cout << diameter << endl;
    return 0;
}