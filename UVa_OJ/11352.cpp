#include <bits/stdc++.h>

using namespace std;

int m, n, xa, xb, ya, yb;
char grid[100][100];
int dist[100][100];
int dx_horse[] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy_horse[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dx_king[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy_king[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void bfs() {
	queue<pair<int, int>> q;
	q.emplace(xa, ya);
	dist[xa][ya] = 0;
	while (!q.empty()) {
		int u = q.front().first, v = q.front().second;
		q.pop();
		for (int i = 0; i < 8; ++i) {
			int x = u + dx_king[i], y = v + dy_king[i];
			if (x < 0 || x >= m || y < 0 || y >= n) continue;
			if (grid[x][y] == 'Z') continue;
			if (dist[x][y] == -1) {
				dist[x][y] = dist[u][v] + 1;
				q.emplace(x, y);
				if (x == xb && y == yb) return;
			}
		}
	}
}

int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		cin >> m >> n;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				dist[i][j] = -1;

		char a[m][n];
		for (int i = 0; i < m; ++i) {
			string s;
			cin >> s;
			for (int j = 0; j < n; ++j) {
				a[i][j] = s[j];
				grid[i][j] = a[i][j];
				if (a[i][j] == 'A') {
					xa = i; 
					ya = j;
				} else if (a[i][j] == 'B') {
					xb = i;
					yb = j;
				}
			}
		}

		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (a[i][j] == 'Z') {
					for (int k = 0; k < 8; ++k) {
						int x = i + dx_horse[k], y = j + dy_horse[k];
						if (x < 0 || x >= m || y < 0 || y >= n) continue;
						if (a[x][y] != '.') continue;
						grid[x][y] = 'Z';
					}
				}
			
		bfs();
		if (dist[xb][yb] == -1) {
			cout << "King Peter, you can't go now!\n";
		} else {
			cout << "Minimal possible length of a trip is " << dist[xb][yb] << endl;
		}
	}
	return 0;
}