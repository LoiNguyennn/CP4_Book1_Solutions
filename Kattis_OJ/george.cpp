#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<ii>> block; // inclusive-exclusive
	block.assign(n, vector<pair<int, int>>(n, {-1, -1}));

	int a, b, k, g;
	cin >> a >> b >> k >> g;
	--a; --b;

	vector<int> george_path(g);
	for (int i = 0; i < g; ++i) {
		cin >> george_path[i];
		--george_path[i];
	}

	vector<vector<ii>> AL(n);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u; --v;
		AL[u].emplace_back(v, w);
		AL[v].emplace_back(u, w);
	}

	int d = 0;
	for (int i = 0; i < g - 1; ++i) {
		int u = george_path[i], v = george_path[i + 1];
		int w;
		for (auto it : AL[u]) {
			if (it.first == v) {
				w = it.second;
				break;
			}
		}

		block[u][v] = {d, d + w};
		block[v][u] = {d, d + w};
		d += w;
	}

	vector<int> dist(n, INF);
	dist[a] = k;
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.push({dist[a], a});

	while (!pq.empty()) {
		int d = pq.top().first, u = pq.top().second;
		pq.pop();
		if (d > dist[u]) continue;
		for (auto it : AL[u]) {
			int v = it.first, w = it.second;
			int dv;
			if (d >= block[u][v].first && d < block[u][v].second) {
				dv = block[u][v].second + w;
			} else {
				dv = d + w;
			}
			if (dist[v] > dv) {
				dist[v] = dv;
				pq.emplace(dv, v);
			}
		}
	}
	cout << dist[b] - k << endl;
	return 0;
}