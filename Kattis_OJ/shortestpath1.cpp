#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

typedef pair<int, int> ii;

int main() {
	int n, m, q, s;
	int tc = 0;
	while (cin >> n >> m >> q >> s) {
		if (n == 0) break;
		if (tc) cout << endl;
		vector<vector<ii>> AL(n);
		for (int i = 0; i < m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			AL[u].emplace_back(v, w);
		}

		int dist[n];
		for (int i = 0; i < n; ++i)
			dist[i] = INF;

		priority_queue<ii, vector<ii>, greater<ii>> pq;
		pq.emplace(0, s);
		dist[s] = 0;
		while (!pq.empty()) {
			int u = pq.top().second, d = pq.top().first;
			pq.pop();
			if (d > dist[u]) continue;
			for (auto x : AL[u]) {
				int v = x.first, w = x.second;
				if (dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
					pq.emplace(dist[v], v);
				}
			}
		}
		for (int i = 0; i < q; ++i) {
			int t;
			cin >> t;
			if (dist[t] == INF)
				cout << "Impossible\n";
			else
				cout << dist[t] << endl;
		}
		++tc;
	}

	return 0;
}