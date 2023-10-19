#include <iostream>
#include <climits>
#include <vector>

#define inf 1e9

using namespace std;

int main() {
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; ++tc) {
        int n, r;
        cin >> n >> r;

        int dist[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                dist[i][j] = inf;
                if (i == j)
                    dist[i][j] = 0;
            }

        for (int i = 0; i < r; ++i) {
            int u, v;
            cin >> u >> v;
            dist[u][v] = dist[v][u] = 1;
        }

        for (int k = 0; k < n; ++k) 
            for (int i = 0; i < n; ++i) 
                for (int j = 0; j < n; ++j) 
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

        int s, d;
        cin >> s >> d;

        int v, mx = 0;
        for (int i = 0; i < n; ++i)
            if (dist[s][i] != inf && dist[i][d] != inf) {
                mx = max(mx, dist[s][i] + dist[i][d]);
            }
        cout << "Case " << tc << ": " << mx << endl;
    }    

    return 0;
}