#include <iostream>
#include <cmath>

#define EPS 1e-8

using namespace std;

typedef long long ll;
typedef long double ld;

ld fastpow(ld a, ll p) {
    if (p == 0) return 1;
    if (p == 1) return a;

    ld k = fastpow(a, p >> 1);
    if (p & 1) {
        return k * k * a;
    } else {
        return k * k;
    }
}

int main() {
    ll x, y, n;
    ld r;
    while (cin >> x >> y >> n >> r) {
        if (x == 0) break;

        r /= 1200;
        n *= 12;
        
        if (fabs(r - ld(0)) < EPS) {
            if (x - y * n <= 0) cout << "YES\n";
            else cout << "NO\n";
            continue;
        }

        ld r1n = fastpow(r + 1, n); // r1n = (r + 1) ^ n
        ld S = x * r1n - y * (r1n  - 1) / r;

        if (S < ld(0)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}