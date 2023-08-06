#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

#define inf 1e9

using namespace std;

typedef tuple<int, int, int> iii;

int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int n, k;

bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		cin >> n >> k;

		int grid[n][n], dist[n][n];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				cin >> grid[i][j];
				grid[i][j] *= -1;
				dist[i][j] = inf;
			}
				
		// dijkstra's
		priority_queue<iii, vector<iii>, greater<iii>> pq; // min heap
		dist[0][0] = grid[0][0];
		pq.push({dist[0][0], 0, 0});
		while (!pq.empty()) {
			int x_u = get<1>(pq.top());
			int y_u = get<2>(pq.top());
			int d = get<0>(pq.top());
			pq.pop();
			if (d > dist[x_u][y_u]) continue;
			for (int i = 0; i < 4; ++i) {
				for (int j = 1; j <= k; ++j) {
					int x_v = x_u + j * dx[i];
					int y_v = y_u + j * dy[i];
					if (valid(x_v, y_v) && grid[x_v][y_v] < grid[x_u][y_u]) {
						int w = grid[x_v][y_v];
						if (dist[x_u][y_u] + w < dist[x_v][y_v]) {
							dist[x_v][y_v] = dist[x_u][y_u] + w;
							pq.push({dist[x_v][y_v], x_v, y_v});
						}
					}
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				ans = min(ans, dist[i][j]);
		}	
		cout << -ans << endl;
		if (TC) cout << endl;
	}
	return 0;
}