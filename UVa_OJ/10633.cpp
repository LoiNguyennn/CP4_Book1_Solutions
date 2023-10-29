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
    ll c;
    while (cin >> c && c) {
        ll a0, b0;
        ll d = ExtendedEuclid(9, 1, a0, b0);
        ll k1 = (b0 * c - 10) / 9 + 1;
        ll k2 = b0 * c / 9;
        vector<ll> solutions;
        for (ll k = k1; k <= k2; ++k) {
            solutions.push_back(10 * (a0 * c + k) + b0 * c - 9 * k);
        }
        for (int i = 0; i < solutions.size() - 1; ++i)
            cout << solutions[i] << " ";
        cout << solutions[solutions.size() - 1] << endl;
    }    
    return 0;
}