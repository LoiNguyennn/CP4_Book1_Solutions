#include <bits/stdc++.h>

#define inf 1e9

using namespace std;

typedef pair<int, int> ii;

void dijkstra(vector<vector<ii>>& AL, int dist[], int s) {
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	dist[s] = 0;
	pq.emplace(0, s);
	while (!pq.empty()) {
		int d = pq.top().first, u = pq.top().second;
		pq.pop();
		if (d > dist[u]) continue;
		for (auto x : AL[u]) {
			int w = x.first, v = x.second;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.emplace(dist[v], v);
			}
		}
	}
}

int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		int n, m, s, t, p;
		cin >> n >> m >> s >> t >> p;
		--s; --t;

		vector<vector<ii>> AL(n);
		vector<vector<ii>> AL_T(n);
		for (int i = 0; i < m; ++i) {
			int u, v, c;
			cin >> u >> v >> c;
			--u; --v;
			AL[u].emplace_back(c, v);
			AL_T[v].emplace_back(c, u);
		}
		
		int dist1[n], dist2[n];
		for (int i = 0; i < n; ++i)
			dist1[i] = dist2[i] = inf;
		
		dijkstra(AL, dist1, s);
		dijkstra(AL_T, dist2, t);

		int ans = -1;

		for (int u = 0; u < n; ++u) {
			for (auto x : AL[u]) {
				int w = x.first, v = x.second;
				if (dist1[u] + w + dist2[v] <= p)
					ans = max(ans, w);
			}
		}
		cout << ans << endl;
	}
	return 0;
}