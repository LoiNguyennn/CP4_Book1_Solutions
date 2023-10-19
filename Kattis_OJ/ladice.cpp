#include <bits/stdc++.h>

using namespace std;

struct UnionFind {
    vector<int> p, s, empty;
    UnionFind(int L) {
        p.resize(L + 1);
        for (int i = 1; i <= L; ++i) p[i] = i;
        s.resize(L + 1, 1);
        empty.resize(L + 1, 1);
    }
    int find_set(int i);
    void union_set(int i, int j);
};

int UnionFind::find_set(int i) {
    if (p[i] == i) return i;
    return p[i] = find_set(p[i]);
}

void UnionFind::union_set(int i, int j) {
    int x = find_set(i), y = find_set(j);
    if (x == y) return;
    if (s[x] > s[y]) swap(x, y);
    p[x] = y;
    s[y] += s[x];
    empty[y] += empty[x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N, L;
    cin >> N >> L;
    UnionFind UF(L);
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        UF.union_set(a, b);
        int parent = UF.find_set(a);
        if (UF.empty[parent]) {
            cout << "LADICA\n";
            --UF.empty[parent];
        } else {
            cout << "SMECE\n";
        }
    }
    return 0;
}