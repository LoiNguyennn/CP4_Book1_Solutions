#include <bits/stdc++.h>

#define inf 1e9

using namespace std;

typedef pair<int, int> ii;

int dist[1000];

void dfs(int u, vector<vector<ii>>& AL) {
	dist[u] = -inf;
	for (auto x : AL[u]) {
		if (dist[x.second] != -inf)
			dfs(x.second, AL);
	}
}

int main() {
	int n, m, q, s;
	while (cin >> n >> m >> q >> s) {
		if (n == 0) break;
		vector<vector<ii>> AL(n);
		for (int i = 0; i < m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			AL[u].emplace_back(w, v);
		}

		for (int i = 0; i < n; ++i)
			dist[i] = inf;
		dist[s] = 0;

		for (int i = 0; i < n - 1; ++i) {
			bool modified = false;
			for (int u = 0; u < n; ++u) {
				if (dist[u] == inf) continue;
				for (auto x : AL[u]) {
					if (dist[u] + x.first < dist[x.second]) {
						dist[x.second] = dist[u] + x.first;
						modified = true;
					}
				}
			}
			if (!modified) break;
		}

		vector<int> in_negative_cycle;
		for (int u = 0; u < n; ++u) {
			if (dist[u] == inf) continue;
			for (auto x : AL[u]) {
				if (dist[u] + x.first < dist[x.second]) 
					in_negative_cycle.push_back(x.second);
			}
		}

		for (int i = 0; i < in_negative_cycle.size(); ++i) {
			if (dist[in_negative_cycle[i]] != -inf)
				dfs(in_negative_cycle[i], AL);
		}
		

		while (q--) {
			int t;
			cin >> t;
			if (dist[t] == inf) {
				cout << "Impossible\n";
			} else if (dist[t] == -inf) {
				cout << "-Infinity\n";
			} else {
				cout << dist[t] << endl;
			}
		}
		cout << endl;
	}
	return 0;
}