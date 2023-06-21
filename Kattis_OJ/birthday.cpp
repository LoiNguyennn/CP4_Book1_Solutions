#include <bits/stdc++.h>

using namespace std;

int dfs_num[100], dfs_low[100], dfs_parent[100];
int counter;
bool hasBridge;

void dfs(int u, vector<vector<int>>& AL) {
	dfs_num[u] = dfs_low[u] = counter++;
	for (int v : AL[u]) {
		if (dfs_num[v] == -1) {
			dfs_parent[v] = u;
			dfs(v, AL);
			if (dfs_low[v] > dfs_num[u]) hasBridge = true;
			dfs_low[u] = min(dfs_low[u], dfs_low[v]); 
		} else if (dfs_parent[u] != v) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int p, c;
	while (cin >> p >> c) {
		if (p == 0 && c == 0) break;
		
		vector<vector<int>> AL(p);
		memset(dfs_num, -1, sizeof(dfs_num));
		counter = 0;
		hasBridge = false;

		for (int i = 0; i < c; ++i) {
			int a, b;
			cin >> a >> b;
			AL[a].push_back(b);
			AL[b].push_back(a);
		}

		int numCCs = 0;
		for (int i = 0; i < p; ++i) {
			if (dfs_num[i] == -1) {
				dfs(i, AL);
				++numCCs;
			}
		}

		if (hasBridge || numCCs > 1) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	return 0;
}