#include <bits/stdc++.h>

using namespace std;

int dfs_num[10000], dfs_low[10000], dfs_parent[10000], AP[10000];
int counter, rootChild, dfs_root;

void articulationPoint(int u, vector<vector<int>>& AL) {
	dfs_num[u] = dfs_low[u] = counter++;
	for (int v : AL[u]) {
		if (dfs_num[v] == -1) {
			dfs_parent[v] = u;
			if (u == dfs_root) ++rootChild;
			articulationPoint(v, AL);
			if (dfs_low[v] >= dfs_num[u])
				++AP[u];
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if (dfs_parent[v] != u) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) return a.second > b.second;
	return a.first < b.first;
}

int main() {
	freopen("input.txt", "r", stdin);
	int n, m;
	int tc = 0;
	while (cin >> n >> m && n) {
		memset(dfs_num, -1, sizeof(dfs_num));
		memset(AP, 0, sizeof(AP));
		int a, b;
		vector<vector<int>> AL(n);
		while (cin >> a >> b && a != -1) {
			AL[a].push_back(b);
			AL[b].push_back(a);
		}

		counter = 0;
		for (int i = 0; i < n; ++i) {
			if (dfs_num[i] == -1) {
				dfs_root = i;
				rootChild = 0;
				articulationPoint(i, AL);
				if (rootChild <= 1) AP[i] = 0;
			}
		}

		vector<pair<int, int>> res;
		for (int i = 0; i < n; ++i) 
			res.push_back({i, AP[i] + 1});
		sort(res.begin(), res.end(), cmp);
		for (int i = 0; i < m; ++i)
			cout << res[i].first << " " << res[i].second << endl;
		cout << endl;
	}
	return 0;
}