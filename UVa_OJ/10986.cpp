#include <bits/stdc++.h>

#define inf 1e9

using namespace std;

typedef pair<int, int> ii;

int main() {
	int TC;
	cin >> TC;
	int tc_counter = 1;
	while (TC--) {
		int n, m, s, t;
		cin >> n >> m >> s >> t;
		vector<vector<ii>> AL(n);
		for (int i = 0; i < m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			AL[u].emplace_back(v, w);
			AL[v].emplace_back(u, w);
		}

		int dist[n];
		for (int i = 0; i < n; ++i)
			dist[i] = inf;
		dist[s] = 0;
		
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		pq.emplace(0, s);

		while (!pq.empty()) {
			int u = pq.top().second, d = pq.top().first;
			pq.pop();
			if (d > dist[u]) continue;
			for (auto x : AL[u]) {
				int v = x.first, w = x.second;
				if (dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					pq.emplace(dist[v], v);
				}
			}
		}


		cout << "Case #" << tc_counter++ << ": ";
		if (dist[t] == inf) {
			cout << "unreachable\n";
		} else {
			cout << dist[t] << endl;
		}
	}
	return 0;
}