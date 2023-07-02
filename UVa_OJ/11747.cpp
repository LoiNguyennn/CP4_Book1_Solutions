#include <bits/stdc++.h>

using namespace std;

struct UnionFind {
	vector<int> parent, rank;
	UnionFind(int V) {
		rank.assign(V, 0);
		parent.resize(V);
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
	}
	bool isSameSet(int u, int v) {
		return find_set(u) == find_set(v);
	}
};

double calcDist(pair<double, double> a, pair<double, double> b) {
	double x = a.first - b.first;
	double y = a.second - b.second;
	return sqrt(x * x + y * y);
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		vector<tuple<int, int, int>> EL;
		for (int i = 0; i < m; ++i) {
			int u, v, w;
			cin >> u >> v >> w;
			EL.emplace_back(w, u, v);
		}
		sort(EL.begin(), EL.end());
		UnionFind UF(n);
		vector<int> w_backedges;
		for (auto x : EL) {
			int w = get<0>(x), u = get<1>(x), v = get<2>(x);
			if (UF.isSameSet(u, v)) {
				w_backedges.push_back(w);
				continue;
			}
			UF.union_set(u, v);
		}
		if (w_backedges.size()) {
			sort(w_backedges.begin(), w_backedges.end());
			for (int i = 0; i < w_backedges.size() - 1; ++i)
				cout << w_backedges[i] << " ";
			cout << w_backedges[w_backedges.size() - 1] << endl;
		} else {
			cout << "forest\n";
		}
	}	
	return 0;
}