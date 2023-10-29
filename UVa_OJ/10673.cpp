#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll ExtendedEuclid(ll a, ll b, ll& p, ll& q) {
    if (b == 0) {
        p = 1;
        q = 0;
        return a;
    }
    ll p1, q1;
    ll d = ExtendedEuclid(b, a % b, p1, q1);
    p = q1;
    q = p1 - (a / b) * q1;
    return d;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        ll x, k;
        cin >> x >> k;
        ll a = floor(1.0 * x / k);
        ll b = ceil(1.0 * x / k);

        ll p0, q0;
        ll d = ExtendedEuclid(a, b, p0, q0);
        
        cout << p0 * x / d << " " << q0 * x / d << endl;
    }    
    return 0;
}