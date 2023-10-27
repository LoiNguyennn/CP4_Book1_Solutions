#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bitset<10000010> bs;
vector<int> p;

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

ll fastpow(int n, int e) {
    if (e == 0) return 1;
    if (e == 1) return n;

    ll x = fastpow(n, e / 2);
    if (e % 2 == 0) return x * x;
    return x * x * n;
}

ll factorize(int n) {
    ll ans = 1;
    for (int i = 0; i < p.size() && p[i] * p[i] <= n; ++i) {
        if (n % p[i] == 0) {
            int exp = 0;
            while (n % p[i] == 0) {
                n /= p[i];
                ++exp;
            }
            ans *= fastpow(exp, p[i]);
        }
    }
    return ans;
}

int main() {
    sieve(20000);

    int n;
    while (cin >> n) {
        cout << n << " " << factorize(n) << endl;
    }       
    return 0;
}