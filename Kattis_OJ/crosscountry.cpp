#include <iostream>
#include <sstream>
#include <vector>

#define inf 1e9

using namespace std;

int main() {
	int n, s, t;
	cin >> n >> s >> t;

	vector<vector<pair<int, int>>> AL(n);
	for (int u = 0; u < n; ++u) {
		for (int v = 0; v < n; ++v) {
			int w;
			cin >> w;
			AL[u].emplace_back(w, v);
		}
	}	

	vector<int> dist(n, inf);
	dist[s] = 0;

	for (int i = 0; i < n - 1; ++i)
		for (int u = 0; u < n; ++u)
			if (dist[u] != inf)
				for (auto x : AL[u]) {
					int v = x.second, w = x.first;
					dist[v] = min(dist[v], dist[u] + w);
				}
	cout << dist[t] << endl;
	return 0;
}