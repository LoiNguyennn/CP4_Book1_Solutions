#include <bits/stdc++.h>

using namespace std;

bool visited[1000];

void dfs(int u, const vector<vector<int>>& AL) {
	visited[u] = true;
	for (int v : AL[u]) {
		if (!visited[v])
			dfs(v, AL);
	}
}

int main() {
	int n;
	cin >> n;
	while (n--) {
		int m, r;
		cin >> m >> r;
		vector<vector<int>> AL(m);
		for (int i = 0; i < r; ++i) {
			int u, v;
			cin >> u >> v;
			AL[u].push_back(v);
			AL[v].push_back(u);
		}
		int ans = -1;
		for (int i = 0; i < m; ++i) {
			if (!visited[i]) {
				dfs(i, AL);
				++ans;
			}
		}
		cout << ans << endl;
		memset(visited, false, sizeof(visited));
	}
	return 0;
}