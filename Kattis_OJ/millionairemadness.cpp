#include <bits/stdc++.h>

#define EPS 1e-6

using namespace std;

int a[1000][1000];
int visited[1000][1000];
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int m, n;

bool valid(int u, int v) {
	if (u < 0 || u >= m || v < 0 || v >= n) return false;
	if (visited[u][v]) return false;
	return true;
}

void dfs(int x, int y, int ladder_height) {
	visited[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		int u = x + dx[i], v = y + dy[i];
		if (valid(u, v)) {
			if (a[u][v] - a[x][y] > ladder_height) continue;
			dfs(u, v, ladder_height);
		}
	}
}

bool possible(int ladder_height) {
	memset(visited, false, sizeof(visited));
	dfs(0, 0, ladder_height);
	return visited[m - 1][n - 1];
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; ++i) 
		for (int j = 0; j < n; ++j) 
			cin >> a[i][j];
	
	int lo = 0, hi = 1e9, ladder_height;
	while (hi - lo > 1) {
		ladder_height = (lo + hi) / 2;
		if (possible(ladder_height)) {
			hi = ladder_height;
		} else {
			lo = ladder_height + 1;
		}
	}
	if (possible(lo)) cout << lo << endl;
	else cout << hi << endl;
	return 0;
}