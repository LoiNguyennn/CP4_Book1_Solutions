#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bitset<10000010> bs;
vector<ll> p;

void sieve(ll n) {
    ll lim = sqrt(n);
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= lim; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j <= lim; j += i)
                bs[j] = 0;
            p.push_back(i);
        }
    }
}

ll factorize(ll n) {
    ll ans = 0;
    for (int i = 0; i < p.size() && p[i] * p[i] <= n; ++i) {
        ll exp = 0;
        while (n % p[i] == 0) {
            ++exp;
            n /= p[i];
        }
        ans += exp;
    }
    if (n > 1) ++ans;
    return ans;
}

int main() {
    ll n;
    cin >> n;    
    sieve(n);
    cout << factorize(n) << endl;
    return 0;
}