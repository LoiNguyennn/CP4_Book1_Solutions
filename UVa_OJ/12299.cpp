#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXN = 100000;
const ll INF = 1e15;

ll st[4 * MAXN], lazy[4 * MAXN];
ll a[MAXN + 5];
char s[MAXN];
int n, q;

void build(int pos, int L, int R) {
    if (L == R) {
        st[pos] = a[L];     
        return;
    }
    int M = (L + R) / 2;
    build(2 * pos, L, M);
    build(2 * pos + 1, M + 1, R);
    st[pos] = min(st[2 * pos], st[2 * pos + 1]);
}

void propagate(int pos) {
    if (lazy[pos]) {
        lazy[2 * pos] += lazy[pos];
        lazy[2 * pos + 1] += lazy[pos];
        st[2 * pos] += lazy[pos];
        st[2 * pos + 1] += lazy[pos];
        lazy[pos] = 0;
    }
}

void update(int pos, int L, int R, int i, int j, int v) {
    if (j < L || R < i) return;
    if (L >= i && R <= j) {
        st[pos] += (R - L + 1) * v;
        lazy[pos] += v;
        return;
    }
    propagate(pos);
    int M = (L + R) / 2;
    update(2 * pos, L, M, i, j, v);
    update(2 * pos + 1, M + 1, R, i, j, v);
    st[pos] = min(st[2 * pos], st[2 * pos + 1]);
}

ll get(int pos, int L, int R, int i, int j) {
    if (j < L || R < i) return INF;
    if (L >= i && R <= j) return st[pos];
    propagate(pos);
    int M = (L + R) / 2;
    return min(get(2 * pos, L, M, i, j), get(2 * pos + 1, M + 1, R, i, j));
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    build(1, 1, n);
    while (q--) {
        scanf("%s", s);
        if (s[0] == 'q') {
            int i, j;
            sscanf( s , "query(%d,%d)" , &i , &j );
            cout << get(1, 1, n, i, j) << endl;
        } else {
            for (int i = 0; s[i]; ++i)
                if (s[i] < '0' || s[i] > '9')
                    s[i] = ' ';
            stringstream ss(s);
            vector<int> shift;
            int x;
            while (ss >> x) shift.push_back(x);

            int i;
            int first_element = a[shift[0]];
            for (i = 0; i < shift.size() - 1; ++i) {
                update(1, 1, n, shift[i], shift[i], a[shift[i + 1]] - a[shift[i]]);
                a[shift[i]] = a[shift[i + 1]];
            }
            update(1, 1, n, shift[i], shift[i], first_element - a[shift[i]]);
            a[shift[i]] = first_element;
        }
    }
    return 0;
}