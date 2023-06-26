#include <bits/stdc++.h>

using namespace std;

bool visited[100000];
int scc[100000];
stack<int> St;
int scc_id;

void kosaraju(int u, vector<vector<int>>& AL, int pass) {
	visited[u] = true;
	for (int v : AL[u]) {
		if (!visited[v])
			kosaraju(v, AL, pass);
	}
	if (pass == 1)
		St.push(u);
	else {
		scc[u] = scc_id;
	}
}

int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; ++i) visited[i] = false;
		while (!St.empty()) St.pop();

		vector<vector<int>> AL(n), AL_T(n);
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			AL[a].push_back(b);
			AL_T[b].push_back(a);
		}

		for (int i = 0; i < n; ++i) 
			if (!visited[i])
				kosaraju(i, AL, 1);
		
		scc_id = 0;
		for (int i = 0; i < n; ++i) visited[i] = false;

		while (!St.empty()) {
			int u = St.top();
			St.pop();
			if (!visited[u]) {
				kosaraju(u, AL_T, 2);
				++scc_id;
			}
		}

		bool hasIncoming[scc_id] = {false};		
		for (int u = 0; u < n; ++u) {
			for (int v : AL[u])
				if (scc[u] != scc[v]) 
					hasIncoming[scc[v]] = true;
		}
		int ans = 0;
		for (int i = 0; i < scc_id; ++i)
			if (!hasIncoming[i]) ++ans;
		cout << ans << endl;
	}
	return 0;
}