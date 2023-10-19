#include <bits/stdc++.h>

using namespace std;

struct UnionFind {
    int p[5001], s[5001]; // parent and size
    int max_size;
    UnionFind(int N) {
        for (int i = 0; i < N; ++i) {
            p[i] = i;
            s[i] = 1;
        }
        max_size = 1;
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
    if (x != y) {
        if (s[x] > s[y]) swap(x, y);
        p[x] = y;
        s[y] += s[x];
        if (s[y] > max_size) max_size = s[y];
    }
}

int main() {
    int C, R;
    while (cin >> C >> R) {
        if (C == 0 && R == 0) break;
        unordered_map<string, int> mp;
        UnionFind UF(C);
        for (int i = 0; i < C; ++i) {
            string s;
            cin >> s;
            mp[s] = i;
        }
        for (int i = 0; i < R; ++i) {
            string s1, s2;
            cin >> s1 >> s2;
            UF.union_set(mp[s1], mp[s2]);
        }
        cout << UF.max_size << endl;
    }
    return 0;
}