#include <bits/stdc++.h>

#define inf 1e9

using namespace std;

typedef pair<int, int> ii;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;

        int dist[n];
        for (int i = 0; i < n; ++i)
            dist[i] = inf;
        dist[0] = 0;

        vector<vector<ii>> AL(n);

        for (int i = 0; i < m; ++i) {
            int x, y, t;
            cin >> x >> y >> t;
            AL[x].emplace_back(t, y);
        }

        
        for (int i = 0; i < n - 1; ++i) { 
            bool modified = false;
            for (int u = 0; u < n; ++u) {
                if (dist[u] == inf) continue;
                for (auto x : AL[u]) { 
                    if (dist[u] + x.first >= dist[x.second]) continue;     
                    dist[x.second] = dist[u] + x.first;
                    modified = true;
                }
            }
            if (!modified) break;
        }

        bool modified = false;
        for (int u = 0; u < n; ++u) {
            for (auto x : AL[u]) { 
                if (dist[u] + x.first >= dist[x.second]) continue;     
                dist[x.second] = dist[u] + x.first;
                modified = true;
            }
        }

        if (modified) {
            cout << "possible\n";
        } else {
            cout << "not possible\n";
        }
    }
    return 0;
}