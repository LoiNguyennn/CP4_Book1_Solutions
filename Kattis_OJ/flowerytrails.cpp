#include <bits/stdc++.h>

#define inf 1e9

using namespace std;

typedef pair<int, int> ii;

bool visited[10000];
int len;

void dfs(int u, vector<vector<ii>>& predecessor) {
    visited[u] = true;
    for (auto x : predecessor[u]) {
        int w = x.first, v = x.second;
        len += w;
        if (!visited[v])
            dfs(v, predecessor);
    }
}

int main() {
    int p, t;
    cin >> p >> t;
    vector<vector<ii>> AL(p);
    
    for (int i = 0; i < t; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        AL[u].emplace_back(w, v);
        AL[v].emplace_back(w, u);
    }

    int source = 0, dest = p - 1;
    int dist[p];
    dist[0] = 0;
    for (int i = 1; i < p; ++i)
        dist[i] = inf;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, source);
    vector<vector<ii>> predecessor(p);
    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d > dist[u] || d > dist[dest]) continue;
        for (auto x : AL[u]) {
            int w = x.first, v = x.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                predecessor[v].clear();
                predecessor[v].emplace_back(w, u);
                pq.emplace(dist[v], v);
            } else if (dist[u] + w == dist[v]) {
                predecessor[v].emplace_back(w, u);
            }
        }
    }
    dfs(dest, predecessor);
    cout << (len << 1) << endl;
    return 0;
}