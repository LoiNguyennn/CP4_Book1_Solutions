#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, c1, n1, c2, n2;

ll ExtendedEuclid(ll a, ll b, ll& x, ll &y) {
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
    while (cin >> n && n) {
        cin >> c1 >> n1 >> c2 >> n2;
        ll x0, y0, d;
        d = ExtendedEuclid(n1, n2, x0, y0);
        if (n % d) {
            cout << "failed\n";
            continue;
        } 
        
        ll k1 = ceil(-1.0 * x0 * n / n2);
        ll k2 = floor(1.0 * y0 * n / n1);
        
        if (k2 < k1) {
            cout << "failed\n";
            continue;
        }

        ll cost1 = c1 * (x0 * n / d + k1 * n2 / d) + c2 * (y0 * n / d - k1 * n1 / d);
        ll cost2 = c1 * (x0 * n / d + k2 * n2 / d) + c2 * (y0 * n / d - k2 * n1 / d);
        
        ll k;
        if (cost1 < cost2) k = k1; // cost function is increasing
        else k = k2;
        ll m1 = x0 * n / d + k * n2 / d;
        ll m2 = y0 * n / d - k * n1 / d;
        cout << m1 << " " << m2 << endl;
    }
    return 0;
}