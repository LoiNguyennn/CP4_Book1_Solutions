#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int M[50];

struct UnionFind {
	vector<int> p, s, popu;

	UnionFind(int n) {
		s.assign(n, 1);
		p.resize(n);
		popu.resize(n);
		for (int i = 0; i < n; ++i) {
			p[i] = i;
			popu[i] = M[i];
		}		
	}

	int find_set(int u) {
		return (p[u] == u) ? u : (p[u] = find_set(p[u]));
	}

	bool isSameSet(int u, int v) {
		return find_set(u) == find_set(v);
	}

	void union_set(int u, int v) {
		int x = find_set(u), y = find_set(v);
		if (x == y) return;
		if (s[x] > s[y]) swap(x, y);
		p[x] = y;
		s[y] += s[x];
		popu[y] += popu[x];
	}

	int getSetPopulation(int u) {
		return popu[find_set(u)];
	}
};

struct Edge {
	int u, v;
	double w;
	Edge(int _u, int _v, double _w) {
		u = _u;
		v = _v;
		w = _w;
	}
	bool operator<(const Edge& other) const {
		return w < other.w;
	}
};

double calcDist(ii a, ii b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	int tc = 0;
	while (cin >> n && n) {
		vector<ii> loc;
		int total_popu = 0;
		for (int i = 0; i < n; ++i) {
			int x, y, m;
			cin >> x >> y >> m;
			loc.push_back({x, y});
			M[i] = m;
			total_popu += m;
		}

		vector<Edge> EL;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				double w = calcDist(loc[i], loc[j]);
				EL.push_back(Edge(i, j, w));
			}
		}
		sort(EL.begin(), EL.end());

		UnionFind UF(n);
		double sum = 0;
		int num_taken = 0;

		for (int i = 0; i < EL.size(); ++i) {
			int u = EL[i].u, v = EL[i].v;
			double w = EL[i].w;
			if (UF.isSameSet(u, v)) continue;
			if (UF.isSameSet(u, 0))
				sum += UF.getSetPopulation(v) * w;
			if (UF.isSameSet(v, 0))
				sum += UF.getSetPopulation(u) * w;
			UF.union_set(u, v);
			++num_taken;
			if (num_taken == n - 1) break;
		}

		cout << "Island Group: " << ++tc << " Average " << fixed << setprecision(2) <<  sum / total_popu << endl;
		cout << endl;
	}	
	return 0;
}