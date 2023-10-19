#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

typedef pair<int, int> ii;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int N, E, T, M;
        cin >> N >> E >> T >> M;
        --E;
        vector<vector<ii>> AL(N);
        for (int i = 0; i < M; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            --u; --v;
            AL[v].emplace_back(u, w); // transpose the graph
        }

        // dijkstra's algorithm
        int dist[N];
        for (int i = 0; i < N; ++i)
            dist[i] = INF;

        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.emplace(0, E);
        dist[E] = 0;
        while (!pq.empty()) {
            int u = pq.top().second, d = pq.top().first;
            pq.pop();
            if (d > dist[u]) continue;
            for (auto x : AL[u]) {
                int v = x.first, w = x.second;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < N; ++i)
            if (dist[i] <= T) 
                ++ans;
        cout << ans << endl;
        if (TC) cout << endl;
    }    
    return 0;
}