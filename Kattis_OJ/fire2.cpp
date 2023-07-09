
#include <bits/stdc++.h>

#define inf 1e9

using namespace std;

int fire_dist[1000][1000], people_dist[1000][1000], dist[1000][1000];
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
char grid[1000][1000];
int w, h, xp, yp; // w, h, pos of people;
vector<pair<int, int>> fire_pos;

bool valid(int x, int y) {
	if (x < 0 || x >= h || y < 0 || y >= w) return false;
	return true;
}

int calcDist() {
	// spread people
	queue<pair<int, int>> q;
	q.emplace(xp, yp);
	people_dist[xp][yp] = 0;
	while (!q.empty()) {
		int u = q.front().first, v = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int x = u + dx[i], y = v + dy[i];
			if (valid(x, y)) {
				if (grid[x][y] == '#' || grid[x][y] == '*') continue;
				if (people_dist[x][y] == -1) {
					people_dist[x][y] = people_dist[u][v] + 1;
					q.emplace(x, y);
				}
			}
		}
	}

	// spread fire
	for (auto i : fire_pos) {
		fire_dist[i.first][i.second] = 0;
		q.emplace(i.first, i.second);
	}
	while (!q.empty()) {
		int u = q.front().first, v = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int x = u + dx[i], y = v + dy[i];
			if (valid(x, y)) {
				if (grid[x][y] == '#') continue;
				if (fire_dist[x][y] == inf) {
					fire_dist[x][y] = fire_dist[u][v] + 1;
					q.emplace(x, y);
				}
			}
		}
	}

	q.emplace(xp, yp);
	dist[xp][yp] = 0;
	int ans = INT_MAX;
	while (!q.empty()) {
		int u = q.front().first, v = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int x = u + dx[i], y = v + dy[i];
			if (valid(x, y)) {
				if (grid[x][y] == '#' || grid[x][y] == '*') continue;
				if (people_dist[x][y] >= fire_dist[x][y]) continue;
				if (dist[x][y] == -1) {
					dist[x][y] = dist[u][v] + 1;
					q.emplace(x, y);
					if (x == 0 || x == h - 1 || y == 0 || y == w - 1)
						ans = min(ans, dist[x][y]);
				}
			}
		}
	}
	return ans;
}

int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		cin >> w >> h;
		for (int i = 0; i < h; ++i) 
			for (int j = 0; j < w; ++j) {
				people_dist[i][j] = -1;
				fire_dist[i][j] = inf;
				dist[i][j] = -1;
			}
		fire_pos.clear();

		for (int i = 0; i < h; ++i) {
			string s;
			cin >> s;
			for (int j = 0; j < w; ++j) {
				grid[i][j] = s[j];
				if (grid[i][j] == '@') {
					xp = i;
					yp = j;
				} else if (grid[i][j] == '*') {
					fire_pos.emplace_back(i, j);
				}
			}
		}
		if (xp == 0 || xp == h - 1 || yp == 0 || yp == w - 1) {
			cout << "1" << endl;
			continue;
		}

		int res = calcDist();
		if (res == INT_MAX) {
			cout << "Impossible\n";
		} else {
			cout << res + 1 << endl;
		}
	}
	return 0;
}