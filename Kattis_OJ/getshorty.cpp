#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

#define INF -1e9

using namespace std;

typedef pair<double, int> ii;

int main() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0) 
			break;
		vector<vector<ii>> AL(n);
		for (int i = 0; i < m; ++i) {
			int x, y;
			double w;
			cin >> x >> y >> w;
			AL[x].emplace_back(w, y);
			AL[y].emplace_back(w, x);
		}

		vector<double> dist(n, INF);
		dist[0] = 1;
		priority_queue<ii> pq;
		pq.emplace(dist[0], 0);
		while (!pq.empty()) {
			double d = pq.top().first;
			int u = pq.top().second;
			pq.pop();
		
			if (d < dist[u]) continue;
			for (auto x : AL[u]) {
				double w = x.first;
				int v = x.second;
				if (dist[u] * w > dist[v]) {
					dist[v] = dist[u] * w;
					pq.emplace(dist[v], v);
				}
			}
		}
		cout << fixed << setprecision(4) << dist[n - 1] << endl;
	}			
	return 0;
}