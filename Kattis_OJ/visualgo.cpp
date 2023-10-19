#include <bits/stdc++.h>

#define inf INT_MAX

using namespace std;

typedef pair<int, int> ii;

int dist[10000], cnt[10000];

int main() {
    int v, e;
    cin >> v >> e;
    vector<vector<ii>> AL(v);
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        AL[u].emplace_back(w, v);
    }    

    int s, t;
    cin >> s >> t;
    for (int i = 0; i < v; ++i)
        dist[i] = inf;
    dist[s] = 0;
    cnt[s] = 1;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.emplace(0, s);

    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto x : AL[u]) {
            int w = x.first, v = x.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
                cnt[v] = cnt[u];
            } else if (dist[u] + w == dist[v]) {
                cnt[v] += cnt[u];
            }
        }
    }

    cout << cnt[t] << endl;
    return 0;
}