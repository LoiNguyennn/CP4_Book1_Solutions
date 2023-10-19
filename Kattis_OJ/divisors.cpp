#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bitset<10000010> bs;
vector<ll> prime;

void sieve() {
    ll lim = 1e7;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i * i <= lim; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j <= lim; j += i)
                bs[j] = 0;
            prime.push_back(i);
        }
    }
}

unordered_map<ll, ll> pf;
void factorize(ll n, ll coef) {
    for (int i = 0; i < prime.size() && prime[i] * prime[i] <= n; ++i) {
        if (n % prime[i] == 0) {
            int exp = 0;
            while (n % prime[i] == 0) {
                ++exp;
                n /= prime[i];
            }
            pf[prime[i]] += exp * coef;
        }
    }
    if (n > 1)
        pf[n] += coef;
}

int main() {
    ll n, k;
    sieve();
    while (cin >> n >> k) {
        pf.clear();
        for (int i = n - k + 1; i <= n; ++i) {
            factorize(i, 1);
        }
        for (int i = 1; i <= k; ++i) {
            factorize(i, -1);
        }

        ll ans = 1;
        for (auto it : pf) {
            ans *= (it.second + 1);
        }
        cout << ans << endl;
    }
    return 0;
}