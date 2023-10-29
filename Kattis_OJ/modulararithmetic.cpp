#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ExtendedEuclid(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll d = ExtendedEuclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}

ll mod(ll x, ll m) {
    return (x % m + m) % m;
}

ll ModInverse(ll b, ll m) {
    ll x, y;
    ll d = ExtendedEuclid(b, m, x, y);
    if (d != 1) return -1;
    return mod(x, m);
}

int main() {
    ll n, t;
    while (cin >> n >> t) {
        if (n == 0 && t == 0) break;
        for (int i = 0; i < t; ++i) {
            ll a, b;
            char op;
            cin >> a >> op >> b;
            if (op == '+') {
                cout << mod(a + b, n) << endl;
            } else if (op == '-') {
                cout << mod(a - b, n) << endl;
            } else if (op == '*') {
                cout << mod(a * b, n) << endl;
            } else {
                int mod_inverse = ModInverse(b, n);
                if (mod_inverse == -1) {
                    cout << -1 << endl;
                } else {
                    cout << ((a % n) * mod_inverse) % n << endl;
                }
            }
        }
    }
    return 0;
}