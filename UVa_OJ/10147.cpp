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
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        vector<pair<int, int>> vertices;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            vertices.emplace_back(x, y);
        }
        vector<tuple<double, int, int>> EL;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double dist = calcDist(vertices[i], vertices[j]);
                EL.emplace_back(dist, i, j);
            }
        }
        sort(EL.begin(), EL.end());

        int m;
        cin >> m;
        int num_taken = 0;
        vector<pair<int, int>> ans;
        UnionFind UF(n);

        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            --u; --v;
            UF.union_set(u, v);
        }

        for (auto x : EL) {
            int w = get<0>(x), u = get<1>(x), v = get<2>(x);
            if (UF.isSameSet(u, v)) continue;
            UF.union_set(u, v);
            ans.emplace_back(u, v);
        }

        if (ans.size() == 0) {
            cout << "No new highways need\n";
        } else {
            for (int i = 0; i < ans.size(); ++i)
                cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
        }

        if (TC) cout << endl;
    }    
    return 0;
}