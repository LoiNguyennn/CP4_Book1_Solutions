#include <bits/stdc++.h>

using namespace std;

vector<int> kahn(vector<vector<int>> AL, int indeg[]) {
	queue<int> q;
	q.push(0);
	vector<int> topo;
	topo.push_back(0);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : AL[u]) {
			--indeg[v];
			if (indeg[v] > 0) continue;
			topo.push_back(v);
			q.push(v);
		}		
	}
	return topo;
}

int main() {
	int n;
	int tc = 0;
	while (cin >> n) {
		vector<vector<int>> AL(n);
		if (tc++) cout << endl;

		int indeg[n];
		memset(indeg, 0, sizeof(indeg));

		for (int u = 0; u < n; ++u) {
			int m;
			cin >> m;
			for (int i = 0; i < m; ++i) {
				int v;
				cin >> v;
				AL[u].push_back(v);
				++indeg[v];
			}
		}

		int num_paths[n];
		memset(num_paths, 0, sizeof(num_paths));
		num_paths[0] = 1;

		vector<int> topo = kahn(AL, indeg);

		for (int u = 0; u < n; ++u)
			for (int v : AL[u])
				num_paths[v] += num_paths[u];	
		
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			if (AL[i].size() == 0)
				ans += num_paths[i];
		}
		cout << ans << endl;
	}
	return 0;
}