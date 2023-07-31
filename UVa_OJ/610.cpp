#include <bits/stdc++.h>

using namespace std;

int dfs_num[1000], dfs_low[1000], dfs_parent[1000], visited[1000];
int dfs_count;
vector<vector<int>> ans;
vector<pair<int, int>> bridges;

void init(int n) {
	ans.clear();
	bridges.clear();
	ans.resize(n);
	for (int i = 0; i < n; ++i) {
		dfs_parent[i] = i;
		visited[i] = 0;
		dfs_num[i] = 0;
		dfs_low[i] = 0;
	}
	dfs_count = 0;
}

void dfs(int u, vector<vector<int>>& AL) {
	dfs_num[u] = dfs_low[u] = dfs_count++;
	visited[u] = 1; // EXPLORED
	for (int v : AL[u]) {
		if (!visited[v]) { 
			dfs_parent[v] = u;
			ans[u].push_back(v);

			dfs(v, AL);
			
			if (dfs_low[v] > dfs_num[u])
				bridges.push_back({u, v});
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if (v != dfs_parent[u]) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
			if (visited[v] == 1) {
				ans[u].push_back(v);
			}
			
		}
	}
	visited[u] = 2;
}

int main() {
	int n, m;
	int tc_counter = 1;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		init(n);
		cout << tc_counter++ << "\n\n";
		vector<vector<int>> AL(n);
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			--u; --v;
			AL[u].push_back(v);
			AL[v].push_back(u);
		}

		dfs(0, AL);

		for (auto x : bridges) {
			bool ok = false;
			for (int i = 0; i < ans[x.first].size(); ++i)
				if (x.second == ans[x.first][i]) {
					ans[x.second].push_back(x.first);
				
					ok = true;
					break;
				}
			if (!ok) {
				ans[x.first].push_back(x.second);
			}
		}

		
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < ans[i].size(); ++j)
				cout << i + 1 << " " << ans[i][j] + 1 << endl;
		cout << "#\n";
	}
	return 0;
}