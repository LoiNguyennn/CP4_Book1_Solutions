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

int c1, c2, d, ans;
stack<int> miniMax;
bool visited[100];

void dfs(int u, vector<vector<pair<int, int>>>& AL_mst) {
    visited[u] = true;
    if (u == c2) {
        while (!miniMax.empty()) {
            ans = max(ans, miniMax.top());
            miniMax.pop();
        }
        return;
    }
    for (auto v : AL_mst[u]) {
        if (!visited[v.first]) {
            miniMax.push(v.second);
            dfs(v.first, AL_mst);
            if (!miniMax.empty())
                miniMax.pop();
        }
    }
}

int main() {
    int C, S, Q;
    int tc_count = 0;
    while (cin >> C >> S >> Q) {
        if (C == 0 && S == 0 && Q == 0) break;
        if (tc_count) cout << endl;

        vector<tuple<int, int, int>> EL;
        vector<vector<pair<int, int>>> AL_mst(C);
        for (int i = 0; i < S; ++i) {
            cin >> c1 >> c2 >> d;
            --c1; --c2;
            EL.emplace_back(d, c1, c2);
        }
        sort(EL.begin(), EL.end());
        UnionFind UF(C);
        int numTaken = 0;
        for (auto x : EL) {
            int w = get<0>(x), u = get<1>(x), v = get<2>(x);
            if (UF.isSameSet(u, v)) continue;
            AL_mst[u].emplace_back(v, w);
            AL_mst[v].emplace_back(u, w);

            UF.union_set(u, v);
            ++numTaken;
            if (numTaken == C - 1) break;
        }
        cout << "Case #" << ++tc_count << "\n";
        while (Q--) {
            ans = -1;
            memset(visited, false, sizeof(visited));
            while (!miniMax.empty()) miniMax.pop();

            cin >> c1 >> c2;
            --c1; --c2;
            dfs(c1, AL_mst);
            if (ans == -1) {
                cout << "no path\n";
            } else {
                cout << ans << endl;
            }
        }
    }    
    return 0;
}