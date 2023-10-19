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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        
        vector<pair<double, double>> V;
        for (int i = 0; i < m; ++i) {
            double a, b;
            cin >> a >> b;
            V.push_back({a, b});
        }

        vector<tuple<double, int, int>> EL;
        for (int i = 0; i < V.size(); ++i)
            for (int j = i + 1; j < V.size(); ++j)
                EL.push_back({calcDist(V[i], V[j]), i, j});                
        sort(EL.begin(), EL.end());

        int numTaken = 0;
        double mst_cost = 0;
        UnionFind UF(V.size());

        for (auto x : EL) {
            double w = get<0>(x);
            int u = get<1>(x), v = get<2>(x);

            if (UF.isSameSet(u, v)) continue;
            mst_cost += w;
            UF.union_set(u, v);
            ++numTaken;
            if (numTaken == V.size() - 1) break;
        }
        cout << fixed << setprecision(14) << mst_cost << endl;
    }    
    return 0;
}