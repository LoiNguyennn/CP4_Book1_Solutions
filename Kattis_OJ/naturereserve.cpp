#include <bits/stdc++.h>

using namespace std;

priority_queue<pair<int, int>> pq;
bool taken[10000];

void process(int u, vector<vector<pair<int, int>>>& AL) {
	taken[u] = true;
	for (auto v : AL[u]) {
		if (!taken[v.first]) { 
			pq.emplace(-v.second, -v.first);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		int n, m, l, s;
		cin >> n >> m >> l >> s;
		for (int i = 0; i < n; ++i) taken[i] = false;
		while (!pq.empty()) pq.pop();

		vector<int> init;
		for (int i = 0; i < s; ++i) {
			int t;
			cin >> t;
			--t;
			taken[t] = true;
			init.push_back(t);
		}

		vector<vector<pair<int, int>>> AL(n);

		for (int i = 0; i < m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			--u; --v;
			AL[u].emplace_back(v, w);
			AL[v].emplace_back(u, w);
		}

		for (int i = 0; i < s; ++i) 
			process(init[i], AL);

		long long ans = 0, num_taken = s;
		while (!pq.empty()) {
			int u = -pq.top().second, w = -pq.top().first;
			pq.pop();
			if (taken[u]) continue;
			ans += w + l;
			++num_taken;
			process(u, AL);
			if (num_taken == n) break;
		}

		cout << ans << endl;
	}	
	return 0;
}