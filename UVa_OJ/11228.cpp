#include <bits/stdc++.h>

#define EPS 1e-7

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
    for (int tc = 1; tc <= TC; ++tc) {
        int n, r;
        cin >> n >> r;
        vector<pair<double, double>> Vertices;
        for (int i = 0; i < n; ++i) {
            double x, y;
            cin >> x >> y;
            Vertices.emplace_back(x, y);
        }
        UnionFind state(n);
        vector<tuple<double, int, int>> EL;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double dist = calcDist(Vertices[i], Vertices[j]);
                if (dist - r < EPS)
                    state.union_set(i, j);
                EL.emplace_back(dist, i, j);
            }
        }


        sort(EL.begin(), EL.end());
        UnionFind UF(n);
        double road_cost = 0, rail_cost = 0;
        int num_taken = 0;
        for (auto x : EL) {
            int u = get<1>(x), v = get<2>(x);
            double w = get<0>(x);
            if (UF.isSameSet(u, v)) continue;
            if (w > r)
                rail_cost += w;
            else
                road_cost += w;
            UF.union_set(u, v);
            ++num_taken;
            if (num_taken == n - 1) break;
        }

        cout << "Case #" << tc << ": " << state.num_sets << " " << int(road_cost + 0.5) << " " << int(rail_cost + 0.5) << endl;
    }    
    return 0;
}