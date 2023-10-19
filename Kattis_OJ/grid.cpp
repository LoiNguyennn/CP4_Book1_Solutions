#include <bits/stdc++.h>

using namespace std;

int grid[500][500], dist[500][500];
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int n, m;

bool possible(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) return false;
    if (dist[x][y] != -1) return false;
    return true;
}

void bfs() {
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    dist[0][0] = 0;
    while (!q.empty()) {
        int u = q.front().first, v = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = u + dx[i] * grid[u][v];
            int y = v + dy[i] * grid[u][v];
            if (possible(x, y)) {
                dist[x][y] = dist[u][v] + 1;
                q.emplace(x, y);
                if (x == n - 1 && y == m - 1) return;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j)
            grid[i][j] = s[j] - '0';
    }    
    bfs();
    cout << dist[n - 1][m - 1] << endl;

    return 0;
}