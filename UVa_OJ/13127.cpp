#include <bits/stdc++.h>

#define inf 1e9

using namespace std;

typedef pair<int, int> ii;

int main() {
	int n, m, b, p;
	while (cin >> n >> m >> b >> p) {
		vector<vector<ii>> AL(n);
		int dist[n];
		priority_queue<ii, vector<ii>, greater<ii>> pq;
		vector<int> banks;

		for (int i = 0; i < n; ++i) dist[i] = inf;

		for (int i = 0; i < m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			AL[u].emplace_back(w, v);
			AL[v].emplace_back(w, u);
		}

		for (int i = 0; i < b; ++i) {
			int t;
			cin >> t;
			banks.emplace_back(t);
		}

		for (int i = 0; i < p; ++i) {
			int t;
			cin >> t;
			dist[t] = 0;
			pq.emplace(0, t);
		}

		// dijkstra's
		while (!pq.empty()) {
			int u = pq.top().second, d = pq.top().first;
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

		sort(banks.begin(), banks.end());
		int E = INT_MIN;
		vector<int> ans;
		for (int i = 0; i < b; ++i) 
			E = max(E, dist[banks[i]]);
		for (int i = 0; i < b; ++i)
			if (dist[banks[i]] == E)
				ans.push_back(banks[i]);
		cout << ans.size() << " ";
		if (E == inf) cout << "*\n";
		else cout << E << endl;

		for (int i = 0; i < ans.size(); ++i) {
			cout << ans[i];
			if (i != ans.size() - 1) cout << " ";
		}
		cout << endl;
	}	
	return 0;
}