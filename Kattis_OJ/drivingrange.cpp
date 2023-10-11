#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

vector<vector<pair<int, int>>> AL;
vector<bool> taken;
priority_queue<ii, vector<ii>, greater<ii>> pq;

void process(int u) {
	taken[u] = true;
	for (auto it : AL[u]) {
		int w = it.first, v = it.second;
		if (!taken[v]) {
			pq.emplace(w, v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	AL.resize(n);
	taken.assign(n, false);

	for (int i = 0; i < m; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		AL[u].emplace_back(w, v);
		AL[v].emplace_back(w, u);
	}

	process(0);

	int max_edge = 0, num_taken = 0;
	while (!pq.empty()) {
		int w = pq.top().first, u = pq.top().second;
		pq.pop();
		if (taken[u]) continue;

		++num_taken;
		max_edge = max(w, max_edge);
		process(u);

		if (num_taken == n - 1) break;
	}

	if (num_taken != n - 1) {
		cout << "IMPOSSIBLE\n";
	} else {
		cout << max_edge << endl;
	}
	return 0;
}