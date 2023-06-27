#include <bits/stdc++.h>

using namespace std;

int val[100], nextVertex, sum;
bool visited[100];

void dfs(int u, vector<vector<int>>& AL) {
	visited[u] = true;
	sum += val[u];
	int mx = 0, flag = 0;
	for (int v : AL[u]) {
		if (!visited[v]) {
			if (val[v] > mx) {
				mx = val[v];
				nextVertex = v;
				flag = 1;
			}
		}
	}
	if (flag) 
		dfs(nextVertex, AL);
}

int main() {
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; ++tc) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
			cin >> val[i];
		memset(visited, 0, sizeof(visited));

		vector<vector<int>> AL(n);
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			AL[a].push_back(b);
		}

		sum = 0;
		dfs(0, AL);
		cout << "Case " << tc << ": " << sum << " " << nextVertex << endl;
	}	
	return 0;
}