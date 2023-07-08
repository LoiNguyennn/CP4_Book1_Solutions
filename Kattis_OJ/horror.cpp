#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int dist[1000];
vector<int> honor;

void bfs(vector<vector<int>>& AL) {
	queue<int> q;
	for (int x : honor) {
		q.push(x);
		dist[x] = 0;
	}

	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : AL[u]) {
			if (dist[v] == INF) {
				q.push(v);
				dist[v] = dist[u] + 1;
			}
		}
	}
}

int main() {
	int n, h, l;
	cin >> n >> h >> l;
	for (int i = 0; i < n; ++i)
		dist[i] = INF;
	for (int i = 0; i < h; ++i) {
		int id;
		cin >> id;
		honor.push_back(id);
	}	
	vector<vector<int>> AL(n);
	for (int i = 0; i < l; ++i) {
		int u, v;
		cin >> u >> v;
		AL[u].push_back(v);
		AL[v].push_back(u);
	}
	bfs(AL);


	int ans = 0, mx = 0;
	for (int i = 0; i < n; ++i) {
		if (dist[i] > mx) {
			mx = dist[i];
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}