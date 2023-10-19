/*
    Fuck this problem statement :)
    If you cannot understand this problem, here is solution for you:
        http://dobrainlog.blogspot.com/p/mall-mania-11101.html
*/

#include <bits/stdc++.h>

using namespace std;

int grid[2001][2001], dist[2001][2001];
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

int main() {    
    while (true) {
        memset(dist, -1, sizeof(dist));
        memset(grid, 0, sizeof(grid));
        queue<pair<int, int>> q;
        int m = 0, n = 0;
        for (int i = 1; i <= 2; ++i) {
            int p;
            cin >> p;
            if (p == 0) 
                return 0;
            for (int j = 0; j < p; ++j) {
                int x, y;
                cin >> x >> y;
                m = max(m, x);
                n = max(n, y);
                grid[x][y] = i;
                if (i == 1)  {
                    dist[x][y] = 0;
                    q.emplace(x, y);
                }
            }
        }
        
        int ans = INT_MAX;
        while (!q.empty()) {
            int u = q.front().first, v = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = u + dx[i], y = v + dy[i];
                if (x < 0 || x > m || y < 0 || y > n) continue;
                if (dist[x][y] == -1) {
                    dist[x][y] = dist[u][v] + 1;
                    q.emplace(x, y);
                    if (grid[x][y] == 2) {
                        ans = min(ans, dist[x][y]);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}