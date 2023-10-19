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

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;
        vector<tuple<int, int, int>> EL;
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            --a; --b;
            EL.emplace_back(c, a, b);
        }
        sort(EL.begin(), EL.end());
        UnionFind UF(n);
        vector<tuple<int, int, int>> mst_edges;
        int S1 = 0;
        for (auto x : EL) {
            int w = get<0>(x), u = get<1>(x), v = get<2>(x);
            if (UF.isSameSet(u, v)) continue;
            UF.union_set(u, v);
            S1 += w;
            mst_edges.emplace_back(w, u, v);
            if (mst_edges.size() == n - 1) break;
        }

        int S2 = INT_MAX;
        for (auto x : mst_edges) {
            int mst_w = get<0>(x), mst_u = get<1>(x), mst_v = get<2>(x);
            UnionFind S(n);
            int mst_cost = 0, num_taken = 0;
            for (auto y : EL) {
                int w = get<0>(y), u = get<1>(y), v = get<2>(y);
                if (w == mst_w && u == mst_u && v == mst_v) continue;
                if (S.isSameSet(u, v)) continue;
                S.union_set(u, v);
                mst_cost += w;
                ++num_taken;
                if (num_taken == n - 1) break;
            }
            if (num_taken == n - 1)
                S2 = min(S2, mst_cost);
        }

        cout << S1 << " " << S2 << endl;
    }    
    return 0;
}