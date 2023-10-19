#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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
    int sizeOfSet(int u) {
        return s[find_set(u)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        
        vector<tuple<int, int, int>> EL;
        for (int i = 0; i < n - 1; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            --u; --v;
            EL.emplace_back(w, u, v);
        }
        sort(EL.begin(), EL.end());

        UnionFind UF(n);
        ll ans = 0;
        for (auto it : EL) {
            int w = get<0>(it), u = get<1>(it), v = get<2>(it);
            ans += w;
            ans += 1ll * (w + 1) * (UF.sizeOfSet(u) * UF.sizeOfSet(v) - 1);
            UF.union_set(u, v);
        }
        cout << ans << endl;
    }
    return 0;
}