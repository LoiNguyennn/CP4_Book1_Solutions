#include <bits/stdc++.h>

#define inf 2e9

using namespace std;

typedef pair<int, int> ii;

int main() {
	int n;
	cin >> n;
	n += 2;
	vector<ii> pos;
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		pos.emplace_back(x, y);
	}

	vector<vector<ii>> AL(n);
	for (int i = 0; i < n; ++i) {
		int x1 = pos[i].first, y1 = pos[i].second;
		for (int j = i + 1; j < n; ++j) {
			int x2 = pos[j].first, y2 = pos[j].second;
			int w = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
			AL[i].emplace_back(w, j);
			AL[j].emplace_back(w, i);
		}
	}


	int dist[n], parent[n];
	for (int i = 0; i < n; ++i)
		dist[i] = inf;
	dist[n - 2] = 0;
	parent[n - 2] = n - 2;

	priority_queue<ii, vector<ii>, greater<ii>> pq;
	pq.emplace(0, n - 2);

	while (!pq.empty()) {
		int d = pq.top().first, u = pq.top().second;
		pq.pop();
		if (d > dist[u]) continue;
		for (auto x : AL[u]) {
			int w = x.first, v = x.second;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.emplace(dist[v], v);
				parent[v] = u;
			}
		}
	}

	vector<int> ans;
	int cur = parent[n - 1];
	while (cur != n - 2) {
		ans.push_back(cur);
		cur = parent[cur];
	}

	if (ans.size() == 0) {
		cout << "-\n";
	} else {
		for (int i = ans.size() - 1; i >= 0; --i)
			cout << ans[i] << endl;
	}
	return 0;
}