#include <bits/stdc++.h>

#define inf 1e9

using namespace std;

void dfs(int u, vector<vector<int>>& AL, int dist[]) {
	dist[u] = -inf;
	for (int v : AL[u]) {
		if (dist[v] != -inf)
			dfs(v, AL, dist);
	}
}

int main() {
	int n;
	while (cin >> n) {
		if (n == -1) break;

		int energy[n];
		vector<vector<int>> AL(n);

		for (int i = 0; i < n; ++i) {
			cin >> energy[i];
			energy[i] = -energy[i];
			int m;
			cin >> m;
			for (int j = 0; j < m; ++j) {
				int x;
				cin >> x;
				--x;
				AL[i].push_back(x);
			}
		}

		int dist[n];
		for (int i = 0; i < n; ++i)
			dist[i] = inf;
		dist[0] = -100;

		for (int i = 0; i < n - 1; ++i) {
			bool modified = false;
			for (int u = 0; u < n; ++u) {
				if (dist[u] > 0) continue;
				for (int v : AL[u]) {
					if (dist[u] + energy[v] >= dist[v]) continue;
					dist[v] = dist[u] + energy[v];
					modified = true;
				}
			}
			if (!modified) break;
		}

		vector<int> in_negative_cycle;
		for (int u = 0; u < n; ++u) {
			if (dist[u] > 0) continue;
			for (int v : AL[u]) {
				if (dist[u] + energy[v] >= dist[v]) continue;
				in_negative_cycle.push_back(v);
			}
		}

		for (int i = 0; i < in_negative_cycle.size(); ++i) {
			if (dist[in_negative_cycle[i]] != -inf)
				dfs(in_negative_cycle[i], AL, dist);
		}

		if (dist[n - 1] < 0) {
			cout << "winnable\n";
		} else {
			cout << "hopeless\n";
		}
	}	
	return 0;
}