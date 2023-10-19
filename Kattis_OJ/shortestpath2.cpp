#include <bits/stdc++.h>

#define inf 1e9
#define eps -1e9

using namespace std;

typedef pair<int, int> ii;

int main() {
    int n, m, queries, s;
    while (cin >> n >> m >> queries >> s) {
        if (n == 0) break;
        vector<vector<tuple<int, int, int, int>>> AL(n);
        for (int i = 0; i < m; ++i) {
            int u, v, t0, P, d;
            cin >> u >> v >> t0 >> P >> d;
            AL[u].emplace_back(d, t0, P, v);
            // AL[v].emplace_back(d, t0, P, u);
        }

        priority_queue<ii, vector<ii>, greater<ii>> q;
        int dist[n];
        for (int i = 0; i < n; ++i)
            dist[i] = inf;
        dist[s] = 0;
        q.emplace(0, s);
        while (!q.empty()) {
            int d = q.top().first, u = q.top().second;
            q.pop();
            if (d > dist[u]) continue;
            for (auto x : AL[u]) {
                int w = get<0>(x), t0 = get<1>(x), P = get<2>(x), v = get<3>(x);
                int actual_weight = w;
                if (P == 0) {
                    if (t0 < dist[u]) continue;
                    actual_weight += t0 - dist[u];
                } else {
                    if (t0 > dist[u])
                        actual_weight += t0 - dist[u];
                    else {
                        int t = (dist[u] - t0) / P;
                        int total = t0 + t * P;
                        if (total < dist[u]) total += P;
                        actual_weight += total - dist[u];
                    }
                
                }

                if (dist[u] + actual_weight < dist[v]) {
                    dist[v] = dist[u] + actual_weight;
                    q.emplace(dist[v], v);
                }
            }
        }

        while (queries--) {
            int dest;
            cin >> dest;
            if (dist[dest] == inf) {
                cout << "Impossible\n";
            } else {
                cout << dist[dest] << endl;
            }
        }
        cout << endl;
    }    
    return 0;
}