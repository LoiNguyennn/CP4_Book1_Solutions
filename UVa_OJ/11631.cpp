#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

priority_queue<ii, vector<ii>, greater<ii>> pq; // prim's algorithm requirement
bool taken[200000];

void process(int u, vector<vector<ii>>& AL) {
	taken[u] = true;
	for (auto v : AL[u])
		if (!taken[v.first])
			pq.emplace(v.second, v.first);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	while (cin >> m >> n) {
		if (m == 0 && n == 0) break;
		for (int i = 0; i < m; ++i) taken[i] = false;
		while (!pq.empty()) pq.pop();

		vector<vector<ii>> AL(m);
		int total_cost = 0;

		for (int i = 0; i < n; ++i) {
			int x, y, z;
			cin >> x >> y >> z;
			total_cost += z;
			AL[x].emplace_back(y, z);
			AL[y].emplace_back(x, z);
		}

		process(0, AL);
		int mst_cost = 0, num_taken = 0;
		while (!pq.empty()) {
			int w = pq.top().first, u = pq.top().second;
			pq.pop();
			if (taken[u]) continue;
			mst_cost += w;
			++num_taken;
			process(u, AL);
			if (num_taken == m - 1) break;
		}
		cout << total_cost - mst_cost << endl;
	}
	return 0;
}