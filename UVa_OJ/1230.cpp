#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;

ll fast_pow(ll x, ll p) {
    if (p == 0) return 1;
    ll ans = fast_pow(x, p / 2);
    if (p & 1) return ((ans % n) * (ans % n) * (x % n)) % n;
    return ((ans % n) * (ans % n)) % n;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        ll x, p;
        cin >> x >> p >> n;
        cout << fast_pow(x, p) << endl;
    }
    cin >> TC;
    return 0;
}