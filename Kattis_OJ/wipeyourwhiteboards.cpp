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

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        ll r, s, q;
        cin >> r >> s >> q;
        s = -s; // prevent negative gcd(r, s)
       
        ll a0, b0;
        ll d = ExtendedEuclid(r, s, a0, b0);
        ll a = a0 * q / d, b = b0 * q / d;

        // switch sign
        s = -s; 
        b = -b;


        // both delta_a and delta_b are < 0
        ll delta_a = s / d, delta_b = -r / d;

        while (a > 0 && b > 0) {
            a += delta_a;
            b += delta_b;
        }

        while (a <= 0 || b <= 0) {
            a -= delta_a;
            b -= delta_b;
        }

        cout << a << " " << b << endl;
    }   
    return 0;
}