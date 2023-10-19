#include <bits/stdc++.h>

using namespace std;

char grid[30][30][30];
int dist[30][30][30];
int dz[] = {-1, 1};
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int L, R, C;


struct Point {
    int z, x, y;
    Point(int _z, int _x, int _y) {
        z = _z;
        x = _x;
        y = _y;
    }
};

bool valid(int z, int x, int y) {
    return (z >= 0 && z < L && x >= 0 && x < R && y >= 0 && y < C && (grid[z][x][y] == '.' || grid[z][x][y] == 'E') && dist[z][x][y] == -1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int zs, xs, ys, ze, xe, ye;
    while (cin >> L >> R >> C) {
        if (L == 0 && R == 0 && C == 0) break;
        for (int z = 0; z < L; ++z) {
            for (int x = 0; x < R; ++x) {
                for (int y = 0; y < C; ++y) {
                    cin >> grid[z][x][y];
                    if (grid[z][x][y] == 'S') {
                        zs = z;
                        xs = x;
                        ys = y;
                    }
                    if (grid[z][x][y] == 'E') {
                        ze = z;
                        xe = x;
                        ye = y;
                    }
                }
            }
        }

        memset(dist, -1, sizeof(dist));
        queue<Point> q;
        q.emplace(Point(zs, xs, ys));
        dist[zs][xs][ys] = 0;
        while (!q.empty()) {
            int z = q.front().z, x = q.front().x, y = q.front().y;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int u = x + dx[i];
                int v = y + dy[i];
                if (valid(z, u, v)) {
                    dist[z][u][v] = dist[z][x][y] + 1;
                    q.emplace(Point(z, u, v));
                }
            }
            for (int i = 0; i < 2; ++i) {
                int t = z + dz[i];
                if (valid(t, x, y)) {
                    dist[t][x][y] = dist[z][x][y] + 1;
                    q.emplace(Point(t, x, y));                    
                }
            }
        }
        if (dist[ze][xe][ye] != -1) {
            cout << "Escaped in " << dist[ze][xe][ye] << " minute(s).\n";
        } else {
            cout << "Trapped!\n";
        }
    }

    return 0;
}