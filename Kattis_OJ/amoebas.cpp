#include <bits/stdc++.h>

using namespace std;

int n, m;
char a[105][105];
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int u, int v) {
	a[u][v] = '.';
	for (int i = 0; i < 8; ++i) {
		int x = u + dr[i];
		int y = v + dc[i];
		if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '#')
			dfs(x, y);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == '#') {
				dfs(i, j);
				++ans;
			}
		}
	}
	cout << ans << endl;
	return 0;
}