#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

class UnionFind {
private:
	vector<int> p, s;
public:
	UnionFind(int n) {
		s.assign(n, 1);
		p.resize(n);
		for (int i = 0; i < n; ++i) 
			p[i] = i;
	}
	int find_set(int u) {
		if (p[u] == u) return u;
		return p[u] = find_set(p[u]);
	}
	void union_set(int u, int v) {
		int x = find_set(u), y = find_set(v);
		if (s[x] > s[y]) swap(x, y);
		p[x] = y;
		s[y] += s[x];
	}
	bool isSameSet(int u, int v) {
		return find_set(u) == find_set(v);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<ii> xs, ys, zs;
	for (int i = 0; i < n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		xs.emplace_back(x, i);
		ys.emplace_back(y, i);
		zs.emplace_back(z, i);
	}

	sort(xs.begin(), xs.end());
	sort(ys.begin(), ys.end());
	sort(zs.begin(), zs.end());

	vector<tuple<int, int, int>> EL;
	for (int i = 0; i < n - 1; ++i) {
		EL.emplace_back(xs[i + 1].first - xs[i].first, xs[i].second, xs[i + 1].second);
		EL.emplace_back(ys[i + 1].first - ys[i].first, ys[i].second, ys[i + 1].second);
		EL.emplace_back(zs[i + 1].first - zs[i].first, zs[i].second, zs[i + 1].second);
	}

	sort(EL.begin(), EL.end());
	
	long long numTaken = 0, mstCost = 0;
	UnionFind UF(n);
	for (auto it : EL) {
		int w = get<0>(it), u = get<1>(it), v = get<2>(it);
		if (UF.isSameSet(u, v)) continue;
		++numTaken;
		mstCost += w;
		UF.union_set(u, v);
		if (numTaken == n - 1) break;
	}
	cout << mstCost << endl;
	return 0;
}