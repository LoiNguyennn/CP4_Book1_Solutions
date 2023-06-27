#include <bits/stdc++.h>

using namespace std;

int dfs_num[10000], dfs_low[10000], inCurrentStack[10000], scc[10000];
stack<int> St;
int dfs_count, scc_id;

void tarjan(int u, vector<vector<int>>& AL) {
	inCurrentStack[u] = true;
	St.push(u);
	dfs_num[u] = dfs_low[u] = dfs_count++;
	for (int v : AL[u]) {
		if (dfs_num[v] == -1)
			tarjan(v, AL);

		if (inCurrentStack[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	} 
	if (dfs_num[u] == dfs_low[u]) {
		while (true) {
			int v = St.top();
			St.pop();
			scc[v] = scc_id;
			inCurrentStack[v] = false;
			if (v == u) break;
		}
		++scc_id;
	}
}

void Reset(int n) {
	for (int i = 0; i < n; ++i) {
		dfs_num[i] = -1;
		inCurrentStack[i] = false;
	}
	dfs_count = 0;
	scc_id = 0;
	while (!St.empty()) St.pop();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; ++tc) {
		int n, m;
		cin >> n >> m;
		Reset(n);

		vector<vector<int>> AL(n);
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			AL[a].push_back(b);
		}

		for (int i = 0; i < n; ++i) 
			if (dfs_num[i] == -1) 
				tarjan(i, AL);
			
		
		bool hasIncoming[scc_id] = {false};
		for (int u = 0; u < n; ++u) 
			for (int v : AL[u])
				if (scc[u] != scc[v]) 
					hasIncoming[scc[v]] = true;
		int ans = 0;
		for (int i = 0; i < scc_id; ++i)
			if (!hasIncoming[i])
				++ans;
		cout << "Case " << tc << ": " << ans << endl;
	}
	return 0;
}