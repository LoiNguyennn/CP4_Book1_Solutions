#include <bits/stdc++.h>

using namespace std;

struct UnionFind {
	vector<int> parent, rank;
	int numSets;
	UnionFind(int V) {
		rank.assign(V, 0);
		parent.resize(V);
		numSets = V;
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
		--numSets;
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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		int S, P;
		cin >> S >> P;
		vector<pair<int, int>> vertices;
		for (int i = 0; i < P; ++i) {
			int x, y;
			cin >> x >> y;
			vertices.emplace_back(x, y);
		}

		vector<tuple<double, int, int>> EL;
		for (int i = 0; i < P; ++i) {
			for (int j = i + 1; j < P; ++j) {
				double dist = calcDist(vertices[i], vertices[j]);
				EL.emplace_back(dist, i, j);
			}
		}
		sort(EL.begin(), EL.end());
		UnionFind UF(P);

		double max_cost = 0;
		for (auto x : EL) {
			double w = get<0>(x), u = get<1>(x), v = get<2>(x);
			if (UF.isSameSet(u, v)) continue;
			max_cost = w;
			UF.union_set(u, v);
			if (UF.numSets == S) break;
		}

		cout << fixed << setprecision(2) << max_cost << endl;
	}	
	return 0;
}