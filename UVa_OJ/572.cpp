#include <bits/stdc++.h>

using namespace std;

char a[100][100];
bool visited[100][100];
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int m, n;

void dfs(int u, int v) {
	visited[u][v] = true;
	for (int i = 0; i < 8; ++i) {
		int x = u + dr[i];
		int y = v + dc[i];
		if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] && a[x][y] == '@')
			dfs(x, y);
	}
}

int main() {
	while (cin >> m >> n) {
		if (m == 0) break;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				cin >> a[i][j];
			
		int ans = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (a[i][j] == '@' && !visited[i][j]) {
					++ans;
					dfs(i, j);
				}
			}
		}
		cout << ans << endl;
		memset(visited, false, sizeof(visited));
	}
	return 0;
}