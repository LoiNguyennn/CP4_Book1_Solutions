#include <bits/stdc++.h>

using namespace std;

int a[500][500], dr[] = {-1, 0, 0, 1}, dc[] = {0, -1, 1, 0};
bool visited[500][500];
int n, m, size_cc;

bool bfs(int u, int v) {
	queue<pair<int, int>> q;
	q.push({u, v});
	visited[u][v] = true;
	bool flag = true;
	while (!q.empty()) {
		++size_cc;
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; ++k) {
			int i = x + dr[k], j = y + dc[k];
			if (i >= 0 && i < n && j >= 0 && j < m) {
				if (a[i][j] > a[x][y]) continue;
				if (a[i][j] < a[x][y]) flag = false;
				if (!visited[i][j] && a[i][j] == a[x][y]) {
					q.push({i, j});
					visited[i][j] = true;
				}
			}
		}
	}
	return flag;
}

int main() {
	memset(visited, false, sizeof(visited));
	cin >> m >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) 
			cin >> a[i][j];
		
	int ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) 
			if (!visited[i][j]) {
				size_cc = 0;
				if (bfs(i, j)) 
					ans += size_cc;
			}
	cout << ans << endl;			
	return 0;
}