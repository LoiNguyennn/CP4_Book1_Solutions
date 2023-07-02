#include <bits/stdc++.h>

using namespace std;

struct UnionFind {
	vector<int> parent, rank;
	int num_sets;
	UnionFind(int V) {
		rank.assign(V, 0);
		parent.resize(V);
		num_sets = V;
		for (int i = 0; i < V; ++i)
			parent[i] = i;
	}
	int find_set(int u) {
		if (parent[u] == u) return u;
		return parent[u] = find_set(parent[u]);
	}
	void union_set(int u, int v) {
		int x = find_set(u), y = find_set(v);
		if (x == y) return;
		if (rank[x] > rank[y]) swap(x, y);
		parent[x] = y;
		if (rank[x] == rank[y]) ++rank[y];
		--num_sets;
	}
	bool isSameSet(int u, int v) {
		return find_set(u) == find_set(v);
	}
};

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		vector<tuple<int, int, int>> EL(n);
		for (int i = 0; i < m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			EL.emplace_back(w, u, v);
		}
		sort(EL.begin(), EL.end());
		UnionFind UF(n);
		int mst_cost = 0;
		set<pair<int, int>> edges;
		for (auto x : EL) {
			int w = get<0>(x), u = get<1>(x), v = get<2>(x);
			if (UF.isSameSet(u, v)) continue;
			mst_cost += w;
			edges.emplace(min(u, v), max(u, v));
			UF.union_set(u, v);
			if (UF.num_sets == 1) break;
		}
		if (UF.num_sets == 1) {
			cout << mst_cost << endl;
			for (auto x : edges) {
				cout << x.first << " " << x.second << endl;
			}
		} else {
			cout << "Impossible\n";
		}
	}
	return 0;
}