#include <bits/stdc++.h>

#define LSO(S) ((S) & (-S))

using namespace std;

typedef long long ll;

ll p[7];
ll ft[7][200001];
ll N, Q;

void update(int gem, int i, int v) {
    for (; i <= N; i += LSO(i)) 
        ft[gem][i] += v;
}

ll RSQ(int gem, int i) {
    ll sum = 0;
    while (i) {
        sum += ft[gem][i];
        i -= LSO(i);
    }
    return sum;
}

ll RSQ(int gem, int l, int r) {
    return RSQ(gem, r) - RSQ(gem, l - 1);
}

void debug() {
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= N; ++j)
            cout << ft[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cin >> N >> Q;
    for (int i = 1; i <= 6; ++i)
        cin >> p[i];

    string s;
    cin >> s;
    vector<int> K;
    K.reserve(s.length() + 1);
    K.push_back(0);
    for (int i = 0; i < N; ++i) K.push_back(s[i] - '0');
    
    // build a fenwick tree
    int a[7][N + 1];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= N; ++i) 
        a[K[i]][i] = 1;
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= N; ++j) {
            ft[i][j] += a[i][j];
            if (j + LSO(j) <= N)
                ft[i][j + LSO(j)] += ft[i][j];
        }
    }

    while (Q--) {
        int op, t1, t2;
        cin >> op >> t1 >> t2;
        if (op == 1) {
            update(K[t1], t1, -1);
            K[t1] = t2;
            update(t2, t1, 1);
        } else if (op == 2) {
            p[t1] = t2;
        } else {
            ll ans = 0;
            for (int i = 1; i <= 6; ++i) {
                ans += RSQ(i, t1, t2) * p[i];
            }
            cout << ans << endl;
        }
    }
    return 0;
}