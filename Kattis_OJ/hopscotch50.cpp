#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, k;
inline int coor_to_idx(int r, int c) { return r * n + c; }
inline int manhattan(int x1, int y1, int x2, int y2) { return abs(x1 - x2) + abs(y1 - y2); }

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    int grid[n][n];

    vector<int> s, d;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 1)
                s.push_back(coor_to_idx(i, j));
            if (grid[i][j] == k)
                d.push_back(coor_to_idx(i, j));
        }

    vector<vector<ii>> AL(n * n);
    vector<int> dist(n * n, INF);


    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) 
            for (int r = 0; r < n; ++r) 
                for (int c = 0; c < n; ++c) 
                    if (grid[i][j] + 1 == grid[r][c]) 
                        AL[coor_to_idx(i, j)].push_back({coor_to_idx(r, c), manhattan(i, j, r, c)});
                    
                
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int x : s) {
        dist[x] = 0;
        pq.emplace(0, x);
    }        
        
    while (!pq.empty()) {
        int d = pq.top().first, u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto it : AL[u]) {
            int v = it.first, w = it.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }

    int ans = INF;
    for (auto x : d)
        ans = min(ans, dist[x]);
    if (ans == INF) {
        cout << "-1\n";
    } else {
        cout << ans << endl;
    }
    return 0;
}