#include <bits/stdc++.h>

using namespace std;

int dfs_num[100], dfs_low[100], dfs_parent[100], AP[100];
int cnt, rootChild, startVertex;

void dfs(int u, vector<vector<int>>& AL) {
	dfs_num[u] = dfs_low[u] = cnt++;
	for (int v : AL[u]) {
		if (dfs_num[v] == -1) {
			dfs_parent[v] = u;
			if (u == startVertex) ++rootChild;
			dfs(v, AL);
			if (dfs_low[v] >= dfs_num[u])
				AP[u] = 1;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if (dfs_parent[v] != u) {
				dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main() {
	int n;
	while (cin >> n && n) {
		cin.ignore();
		string str;
		memset(dfs_num, -1, sizeof(dfs_num));
		memset(AP, 0, sizeof(AP));
		vector<vector<int>> AL(n + 1);
		while (getline(cin, str) && str != "0") {
			stringstream sin(str);
			int u, v;
			sin >> u;
			while (sin >> v) {
				AL[u].push_back(v);
				AL[v].push_back(u);
			}
		}

		for (int i = 1; i <= n; ++i) {
			if (dfs_num[i] == -1) {
				cnt = rootChild = 0;
				startVertex = i;
				dfs(i, AL);
				if (rootChild <= 1) AP[i] = 0;
			}

		}
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			if (AP[i]) ++ans;
		cout << ans << endl;

	}	
	return 0;
}