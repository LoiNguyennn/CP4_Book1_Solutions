#include <bits/stdc++.h>

#define inf 1e9

using namespace std;

typedef pair<int, int> ii;

int main() {
    int n, m, a, k;
    while (cin >> n >> m >> a >> k) {
        int dist[n];
        for (int i = 0; i < n; ++i)
            dist[i] = inf;

        vector<vector<ii>> AL(n);

        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            --u; --v;
            AL[u].emplace_back(w, v);
            AL[v].emplace_back(w, u);
        }

        priority_queue<ii, vector<ii>, greater<ii>> pq;
        for (int i = 0; i < a; ++i) {
            int b;
            cin >> b;
            --b;
            dist[b] = 0;
            pq.emplace(0, b);
            while (!pq.empty()) {
                int d = pq.top().first, u = pq.top().second;
                pq.pop();
                if (d > dist[u]) continue;
                for (auto x : AL[u]) {
                    int w = x.first, v = x.second;
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        pq.emplace(dist[v], v);
                    }
                }
            }

            int ans = 0;
            for (int i = 0; i < n; ++i)
                if (dist[i] >= k)
                    ++ans;
            cout << ans << endl;
        }
        cout << endl;
    }
    return 0;
}