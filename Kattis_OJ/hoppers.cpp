#include <bits/stdc++.h>

using namespace std;

bool isBipartite;

void bfs(int s, vector<vector<int>>& AL, vector<int>& colored) {
	queue<int> q;
	q.push(s);
	colored[s] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : AL[u]) {
			if (colored[v] == -1) {
				colored[v] = 1 - colored[u];
				q.push(v);
			} else if (colored[v] == colored[u]) {
				isBipartite = false;
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> AL(n);
	vector<int> colored(n, -1);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		AL[a].push_back(b);
		AL[b].push_back(a);
	}

	isBipartite = true;
	int numCCs = 0;
	for (int i = 0; i < n; ++i) {
		if (colored[i] == -1) {
			++numCCs;
			bfs(i, AL, colored);
		}
	}
	if (isBipartite) {
		cout << numCCs << endl;
	} else {
		cout << numCCs - 1 << endl;
	}
	return 0;
}