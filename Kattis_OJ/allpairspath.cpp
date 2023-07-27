#include <iostream>

#define inf 1e9

using namespace std;

int main() {
	int n, m, q;
	while (cin >> n >> m >> q) {
		if (n == 0) break;

		int dist[n][n];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) 
				dist[i][j] = inf;
		for (int i = 0; i < n; ++i)
			dist[i][i] = 0;
			

		for (int i = 0; i < m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			dist[u][v] = min(dist[u][v], w);
		}

		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j) {
					if (dist[i][k] < inf && dist[k][j] < inf)
						dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				}

		for (int i = 0; i < n; ++i) 
			for (int j = 0; j < n; ++j)
				for (int k = 0; k < n; ++k)
					if (dist[k][k] < 0 && dist[i][k] != inf && dist[k][j] != inf)
						dist[i][j] = -inf;

		while (q--) {
			int u, v;
			cin >> u >> v;
			if (dist[u][v] == inf) {
				cout << "Impossible\n";
			} else if (dist[u][v] == -inf) {
				cout << "-Infinity\n";
			} else {
				cout << dist[u][v] << endl;
			}
		}	
		cout << endl;			
	}
	return 0;
}