#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bitset<10000050> bs;
vector<ll> p;

void sieve(ll upperBound) {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= upperBound; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j <= upperBound; j += i)
                bs[j] = 0;
            p.push_back(i);
        }
    }
}

ll factorize(ll n) {
    vector<ll> v;
    for (int i = 0; i < p.size() && p[i] * p[i] <= n; ++i) {
        if (n % p[i] == 0) {
            while (n % p[i] == 0)
                n /= p[i];
            v.push_back(p[i]);
        }
    }
    if (n > 1)
        v.push_back(n);
    if (v.size() <= 1) return -1;
    return v[v.size() - 1];
}

int main() {
    ll n;
    sieve(1e7 + 30);
    while (cin >> n && n) {
        cout << factorize(abs(n)) << endl;
    }
    return 0;
}