#include <bits/stdc++.h>

using namespace std;

int m, n;
int a[1000][1000], dr[] = {-1, 0, 0, 1}, dc[] = {0, -1, 1, 0};

void dfs(int u, int v, int label) {
	// partition the map into connected continents 
	// labeled with negative number(0-area) or number >= 2 (1-area)
	// negative and  >= 2 just avoid repeating 0 and 1 in the initial grid
	int cur_type = (label < 0) ? 0 : 1;
	a[u][v] = label;
	for (int i = 0; i < 4; ++i) {
		int x = u + dr[i], y = v + dc[i];
		if (x >= 0 && x < m && y >= 0 && y < n && a[x][y] == cur_type) {
			dfs(x, y, label);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n;
	for (int i = 0; i < m; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j)
			a[i][j] = s[j] - '0';
	}

	int label_binary = -1, label_decimal = 2;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j] == 1) {
				dfs(i, j, label_decimal);
				++label_decimal;
			} else if (a[i][j] == 0) {
				dfs(i, j, label_binary);			
				--label_binary;
			}
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		--r1; --r2; --c1; --c2;
		if (a[r1][c1] != a[r2][c2]) {
			cout << "neither\n";
		} else if (a[r1][c1] < 0) {
			cout << "binary\n";
		} else {
			cout << "decimal\n";
		}
	}
	return 0;
}