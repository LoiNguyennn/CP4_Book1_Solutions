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
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<tuple<int, int, int>> EL;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int d;
            cin >> d;
            if (i != j)
                EL.emplace_back(d, i, j);
        }
    }

    sort(EL.begin(), EL.end());
    vector<pair<int, int>> ans;
    UnionFind UF(n);
    int num_taken = 0;
    for (auto x : EL) {
        int d = get<0>(x), u = get<1>(x), v = get<2>(x);
        if (UF.isSameSet(u, v)) continue;
        ans.emplace_back(u, v);
        ++num_taken;
        UF.union_set(u, v);
        if (num_taken == n - 1) break;
    }
    for (auto x : ans) {
        cout << x.first + 1 << " " << x.second + 1 << endl;
    }
    return 0;
}