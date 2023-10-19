#include <bits/stdc++.h>

using namespace std;

int dist[100][100];
int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int r, c, gr, gc, lr, lc;

int bfs() {
    queue<pair<int, int>> q;
    dist[gr][gc] = 0;
    q.emplace(gr, gc);
    while (!q.empty()) {
        int u = q.front().first, v = q.front().second;
        q.pop();
        for (int i = 0; i < 8; ++i) {
            int x = u + dx[i], y = v + dy[i];
            if (x < 0 || x >= r || y < 0 || y >= c) continue;
            if (dist[x][y] == -1) {
                dist[x][y] = dist[u][v] + 1;
                q.emplace(x, y);
            }
            if (x == lr && y == lc) {
                return dist[x][y];
            }
        }
    }
    return dist[lr][lc];
}

int main() {
    while (cin >> r >> c >> gr >> gc >> lr >> lc) {
        --gr; --gc; --lr; --lc;
        memset(dist, -1, sizeof(dist));
        int res = bfs();
        if (res == -1) {
            cout << "impossible\n";
        } else {
            cout << res << endl;
        } 
    }
    return 0;
}