#include <bits/stdc++.h>

#define LSOne(S) ((S) & (-S))

using namespace std;

struct FenwickTree {
    vector<int> ft;
    void build(const vector<int>& a);
    void update(int i, int v);
    int RSQ(int i);
    int RSQ(int l, int r);
    FenwickTree(const vector<int>& a) {
        ft.resize(a.size(), 0);
        build(a);
    }
};

int FenwickTree::RSQ(int i) {
    int sum = 0;
    while (i) {
        sum += ft[i];
        i -= LSOne(i);
    }
    return sum;
}

int FenwickTree::RSQ(int l, int r) {
    return RSQ(r) - RSQ(l - 1);
}

void FenwickTree::update(int i, int v) {
    while (i < ft.size()) {
        ft[i] += v;
        i += LSOne(i);
    }
}

void FenwickTree::build(const vector<int>& a) {
    for (int i = 1; i < ft.size(); ++i) {
        ft[i] += a[i];
        if (i + LSOne(i) < ft.size())
            ft[i + LSOne(i)] += ft[i];
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1, 0);
    FenwickTree ft(a);
    for (int i = 0; i < k; ++i) {
        char op;
        cin >> op;
        if (op == 'F') {
            int t;
            cin >> t;
            if (a[t]) {
                ft.update(t, -1);
                a[t] = 0;
            } else {
                ft.update(t, 1);
                a[t] = 1;
            }
        } else {
            int l, r;
            cin >> l >> r;
            cout << ft.RSQ(l, r) << endl;    
        }
    }
    return 0;
}