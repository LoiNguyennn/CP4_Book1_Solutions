#include <bits/stdc++.h>

using namespace std;

bool visited[26][26];
int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n;

void dfs(const vector<string>& a, int u, int v) {
	visited[u][v] = true;
	for (int i = 0; i < 8; ++i) {
		int x = u + dr[i];
		int y = v + dc[i];
		if (x >= 0 && x < n && y >= 0 && y < n && !visited[x][y] && a[x][y] == '1')
			dfs(a, x, y);
	}
}

int main() {
	int tc = 1;
	while (cin >> n) {
		vector<string> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
			
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (a[i][j] == '1' && !visited[i][j]) {
					++ans;
					dfs(a, i, j);
				}
			}
		}
		cout << "Image number " << tc++ << " contains " << ans << " war eagles.\n";
		memset(visited, false, sizeof(visited));
	}
	return 0;
}