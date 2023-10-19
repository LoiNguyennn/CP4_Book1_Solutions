#include <bits/stdc++.h>

using namespace std;

int r1, c1, r2, c2, r3, c3;
int dist[8][8], dx[] =  {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void bfs() {
    queue<pair<int, int>> q;
    q.emplace(r1, c1);
    dist[r1][c1] = 0;
    while (!q.empty()) {
        int u = q.front().first, v = q.front().second;
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int x = u + dx[i], y = v + dy[i];
            if (x < 0 || x >= 8 || y < 0 || y >= 8) continue;
            if (x == r3 && y == c3) continue;
            if (dist[x][y] == -1) {
                dist[x][y] = dist[u][v] + 1;
                q.emplace(x, y);
                if (x == r2 && y == c2) return;
            } 
        }
    }
}

int main() {
    int tc_counter = 1;

    while (cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3) {
        memset(dist, -1, sizeof(dist));
        --r1; --c1; --r2; --c2; --r3; --c3;
        r1 = 7 - r1; r2 = 7 - r2; r3 = 7 - r3;
        bfs();
        cout << "Case " << tc_counter++ << ": " << dist[r2][c2] << endl;
    }

    return 0;
}