#include <bits/stdc++.h>

using namespace std;

int R, C, x_source, y_source, x_dest, y_dest;
int grid[1000][1000], dist[1000][1000];
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

bool possible(int x, int y) {
	if (x < 0 || x >= R || y < 0 || y >= C) return false;
	if (dist[x][y] != 0 || grid[x][y] == 1) return false;
	return true;
}

void bfs() {
	queue<pair<int , int>> pq;
	pq.emplace(x_source, y_source);
	dist[x_source][y_source] = 0;
	while (!pq.empty()) {
		int u = pq.front().first, v = pq.front().second;
		pq.pop();
		for (int i = 0; i < 4; ++i) {
			int x = u + dx[i];
			int y = v + dy[i];
			if (possible(x, y)) {
				pq.emplace(x, y);
				dist[x][y] = dist[u][v] + 1;
				if (x == x_dest && y == y_dest) return;
			}
		}
	}
}

int main() {
	while (cin >> R >> C) {
		if (R == 0 && C == 0) break;
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				grid[i][j] = 0;
				dist[i][j] = 0;
			}
		}

		int nr;
		cin >> nr;
		for (int i = 0; i < nr; ++i) {
			int r, nb;
			cin >> r >> nb;
			for (int j = 0; j < nb; ++j) {
				int c;
				cin >> c;
				grid[r][c] = 1;
			}
		}
		cin >> x_source >> y_source >> x_dest >> y_dest;
		bfs();
		cout << dist[x_dest][y_dest] << endl;
	}
	return 0;
}