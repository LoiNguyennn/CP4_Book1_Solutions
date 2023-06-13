#include <bits/stdc++.h>

using namespace std;

int a[1000][1000], dr[] = {-1, 0, 0, 1}, dc[] = {0, -1, 1, 0};
int mp[1000][1000];
int n, m, ans = 0;

void dfs(int u, int v, int label) {
	mp[u][v] = label;
	if (label == 0) {
		for (int i = 0; i < 4; ++i) {
			int x = u + dr[i], y = v + dc[i];
			if (x >= 0 && x < n && y >= 0 && y < m && mp[x][y] == -1 && a[x][y] == 0)
				dfs(x, y, label);
		}
	} else {
		for (int i = 0; i < 4; ++i) {
			int x = u + dr[i], y = v + dc[i];
			if (x < 0 || x >= n || y < 0 || y >= m) ++ans;
			else if (x >= 0 && x < n && y >= 0 && y < m) {
				if (mp[x][y] == 0) {
					++ans;
					continue;
				}
				if (a[x][y] == 1 && mp[x][y] == -1) dfs(x, y, label);	
			}
		}
	}
}

int main() {
	memset(mp, -1, sizeof(mp));
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			a[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < m; ++i) {
		if (a[0][i] == 0 && mp[0][i] == -1)
			dfs(0, i, 0);
		if (a[n - 1][i] == 0 && mp[n - 1][i] == -1)
			dfs(n - 1, i, 0); 
	}

	for (int i = 0; i < n; ++i) {
		if (a[i][0] == 0 && mp[i][0] == -1)
			dfs(i, 0, 0);
		if (a[i][m - 1] == 0 && mp[i][m - 1] == -1)
			dfs(i, m - 1, 0); 
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 1 && mp[i][j] == -1)
				dfs(i, j, 1);
		}
	}
	cout << ans << endl;
	return 0;
}