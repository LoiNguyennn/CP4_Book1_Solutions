#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int u, v;
	double w;
	bool operator < (const Edge& other) {
		return w < other.w;
	}
};

int parent[1000], r[1000];

int find_set(int u) {
	if (parent[u] == u) return u;
	return parent[u] = find_set(parent[u]);
}
void union_set(int u, int v) {
	int x = find_set(u), y = find_set(v);
	if (x == y) return;
	if (r[x] > r[y]) swap(x, y);
	parent[x] = y;
	if (r[x] == r[y]) ++r[y];
}
bool isSameSet(int u, int v) {
	return find_set(u) == find_set(v);
}


double calcDist(pair<double, double> a, pair<double, double> b) {
	double x = a.first - b.first;
	double y = a.second - b.second;
	return sqrt(x * x + y * y);
}

double kruskal(int n, vector<Edge> EL) {
	sort(EL.begin(), EL.end());
	int numTaken = 0;
	double mst_cost = 0;

	for (auto x : EL) {
		double w = x.w;
		int u = x.u, v = x.v;

		if (isSameSet(u, v)) continue;
		mst_cost += w;
		union_set(u, v);
		++numTaken;
		if (numTaken == n - 1) break;
	}
	return mst_cost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int TC;
	cin >> TC;
	while (TC--) {
		int m;
		cin >> m;
		
		vector<pair<double, double>> V;
		for (int i = 0; i < m; ++i) {
			double a, b;
			cin >> a >> b;
			V.push_back({a, b});
		}

		vector<Edge> EL;
		for (int i = 0; i < V.size(); ++i)
			for (int j = i + 1; j < V.size(); ++j) {
				Edge a;
				a.u = i;
				a.v = j;
				a.w = calcDist(V[i], V[j]);
				EL.push_back(a);
			}
		for (int i = 0; i < m; ++i) {
			parent[i] = i;
			r[i] = 0;
		}
						
		cout << fixed << setprecision(2) << kruskal(m, EL) << endl;
		if (TC) cout << endl;
	}	
	return 0;
}