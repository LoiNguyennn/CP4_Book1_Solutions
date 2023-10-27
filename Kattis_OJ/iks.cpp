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

unordered_map<int, vector<int>> f;
unordered_map<ll, ll> factorize(int n) {
    unordered_map<ll, ll> ans;
    for (int i = 0; i < p.size() && p[i] * p[i] <= n; ++i) {
        if (n % p[i] == 0) {
            int exp = 0;
            while (n % p[i] == 0) {
                n /= p[i];
                ++exp;
            }
            f[p[i]].push_back(exp);
            ans[p[i]] = exp;
        }
    }
    if (n > 1) {
        f[n].push_back(1);
        ans[n] = 1;
    }
    return ans;
}

ll fastpow(int n, int e) {
    if (e == 0) return 1;
    if (e == 1) return n;

    ll x = fastpow(n, e / 2);
    if (e % 2 == 0) return x * x;
    return x * x * n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    sieve(sqrt(1000000));

    int n;
    cin >> n;
    vector<unordered_map<ll, ll>> in;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        in.push_back(factorize(x));
    }
    int greatest_gcd = 1;

    int t = 0;
    for (auto& [p, v] : f) {
        int ave = 0;
        for (int i : v)
            ave += i;
        ave /= n;
        greatest_gcd *= fastpow(p, ave);
        for (auto x : in)
            if (x[p] < ave)
                t += ave - x[p];

    }

    cout << greatest_gcd << " " << t << endl;
    return 0;
}