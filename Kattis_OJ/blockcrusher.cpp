#include <bits/stdc++.h>

#define inf 1e9

using namespace std;

typedef pair<int, int> ii;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1}, dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int h, w;

bool valid(int x, int y) {
	return x >= 0 && x < h && y >= 0 && y < w;
}

int main() {
	while (cin >> h >> w) {
		if (h == 0) break;

		int grid[h][w], dist[h][w];
		ii parent[h][w];

		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j) {
				dist[i][j] = inf;
				parent[i][j] = make_pair(i, j); 
			}

		for (int i = 0; i < h; ++i) {
			string s;
			cin >> s;
			for (int j = 0; j < w; ++j)
				grid[i][j] = s[j] - '0';
		}

		priority_queue<pair<int, ii>, vector<pair<int, ii>>, greater<pair<int, ii>>> pq;
		for (int i = 0; i < w; ++i) {
			dist[0][i] = grid[0][i];
			pq.emplace(0, make_pair(0, i));
		}

		while (!pq.empty()) {
			int d = pq.top().first, ux = pq.top().second.first, uy = pq.top().second.second;
			pq.pop();

			if (d > dist[ux][uy]) continue;
			for (int i = 0; i < 8; ++i) {
				int vx = ux + dx[i], vy = uy + dy[i];
				if (valid(vx, vy)) {
					int w = grid[vx][vy];
					if (dist[ux][uy] + w < dist[vx][vy]) {
						dist[vx][vy] = dist[ux][uy] + w;
						parent[vx][vy] = make_pair(ux, uy);
						pq.emplace(dist[vx][vy], make_pair(vx, vy));
					}
				}
			}	
		}

		int dest_x = h - 1, dest_y, mi = INT_MAX;
		for (int i = 0; i < w; ++i)
			if (dist[h - 1][i] < mi) {
				mi = dist[h - 1][i];
				dest_y = i;
			}
	
		while (true) {
			grid[dest_x][dest_y] = 0;
			int x = parent[dest_x][dest_y].first;
			int y = parent[dest_x][dest_y].second;
			if (dest_x == x && dest_y == y) break;
			dest_x = x;
			dest_y = y;
		}

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				if (grid[i][j] == 0) cout << " ";
				else cout << grid[i][j];
			}
			cout << endl;
		}
	}	
	return 0;
}