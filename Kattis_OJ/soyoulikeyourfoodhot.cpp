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
    double pt, p1, p2;
    cin >> pt >> p1 >> p2;

    ll n = pt * 100 + 0.5;
    ll a = p1 * 100 + 0.5;
    ll b = p2 * 100 + 0.5;

    ll x0, y0;
    ll d = ExtendedEuclid(a, b, x0, y0);


    if (n % d) {
        cout << "none\n";
        return 0;
    }

    ll k1 = ceil(-1.0 * x0 * n / b);
    ll k2 = floor(1.0 * y0 * n / a);
    if (k2 < k1) {
        cout << "none\n";
        return 0;
    }

    vector<pair<ll, ll>> solutions;
    for (ll k = k1; k <= k2; ++k) {
        solutions.push_back({x0 * (n / d) + k * b / d, y0 * (n / d) - k * a / d});
    }
    for (auto it : solutions) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}