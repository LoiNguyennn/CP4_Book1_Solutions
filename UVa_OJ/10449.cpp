#include <bits/stdc++.h>

#define inf 1e9

using namespace std;

typedef pair<int, int> ii;

int main() {
	int n;
	int tc = 1;
	while (cin >> n) {
		int busyness[n];
		for (int i = 0; i < n; ++i)
			cin >> busyness[i];
		int r;
		cin >> r;

		vector<vector<ii>> AL(n);
		for (int i = 0; i < r; ++i) {
			int u, v, w;
			cin >> u >> v;
			--u; --v;
			w = pow(busyness[v] - busyness[u], 3);
			AL[u].emplace_back(w, v);
		}


		int dist[n];
		for (int i = 0; i < n; ++i)
			dist[i] = inf;

		dist[0] = 0;
		bool modified;
		for (int i = 0; i < n - 1; ++i) {
			modified = false;
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


		for(int i = 0; i < n - 1; ++i)
			for(int u = 0; u < n; ++u) {
				if (dist[u] == inf) continue;
				for(auto x : AL[u])
					if(dist[u] + x.first < dist[x.second])
						dist[x.second] = 0;
		}

		int q;
		cin >> q;
		cout << "Set #" << tc++ << endl;
		while (q--) {
			int t;
			cin >> t;
			--t;
			if (dist[t] < 3 || dist[t] == inf)
				cout << "?\n";
			else
				cout << dist[t] << endl;
		}
	}
	return 0;
}