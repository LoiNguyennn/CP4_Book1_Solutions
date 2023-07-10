#include <bits/stdc++.h>

using namespace std;

int grid[1000][1000], cost[1000][1000];
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int r, c, rs, cs, rd, cd;

void bfs() {
	deque<pair<int, int>> dq;
	cost[rs][cs] = 0;
	dq.push_front({rs, cs});
	while (!dq.empty()) {
		int u = dq.front().first, v = dq.front().second;
		dq.pop_front();
		for (int i = 0; i < 8; ++i) {
			int x = u + dx[i], y = v + dy[i];
			if (x < 0 || x >= r || y < 0 || y >= c) continue;
			if (cost[x][y] != -1)
				if (cost[x][y] <= cost[u][v] + (i != grid[u][v]))
					continue;
			
			cost[x][y] = cost[u][v] + (i != grid[u][v]);
			
			if (i == grid[u][v]) dq.push_front({x, y});
			else dq.push_back({x, y});
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < c; ++j)
			grid[i][j] = s[j] - '0';
	}

	int n;
	cin >> n;
	while (n--) {
		cin >> rs >> cs >> rd >> cd;
		--rs; --cs; --rd; --cd;
		memset(cost, -1, sizeof(cost));
		bfs();
		cout << cost[rd][cd] << endl;
	}
	return 0;
}