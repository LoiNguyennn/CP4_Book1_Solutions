#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bitset<10000010> bs;
vector<ll> p;

void sieve() {
    ll lim = 1e7;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i * i <= lim; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j <= lim; j += i) {
                bs[j] = 0;
            }
            p.push_back(i);
        }
    }
}

ll sumDiv(ll n) {
    ll ans = 1;
    for (int i = 0; i < p.size() && p[i] * p[i] <= n; ++i) {
        ll multiplier = p[i], total = 1;
        while (n % p[i] == 0) {
            n /= p[i];
            total += multiplier;
            multiplier *= p[i];
        }
        ans *= total;
    }
    if (n > 1)
        ans *= (1 + n);
    return ans;
}

int main() {
    ll n;
    sieve();
    while (cin >> n) {
        cout << n << " ";
        int diff = abs(n - (sumDiv(n) - n));
        if (diff == 0)
            cout << "perfect\n";
        else if (diff <= 2)
            cout << "almost perfect\n";
        else
            cout << "not perfect\n";
    }
    return 0;
}