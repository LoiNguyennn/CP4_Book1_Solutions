#include <bits/stdc++.h>

#define MAXN int(1000000)

using namespace std;

typedef long long ll;
const ll p = 131;
const ll MOD = 1e9 + 7;

ll P[MAXN], P_inv[MAXN];

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

ll modInverse(ll b, ll MOD) {
    ll x, y;
    ExtendedEuclid(b, MOD, x, y);
    return (x % MOD + MOD) % MOD;
}

void ComputeP(int n) {
    P[0] = 1;
    for (int i = 1; i < n; ++i) 
        P[i] = (P[i - 1] * p) % MOD;
}

void ComputePInverse(int n) {
    P_inv[n - 1] = modInverse(P[n - 1], MOD);
    for (int i = n - 2; i >= 0; i--) P_inv[i] = (P_inv[i + 1] * p) % MOD;
}

vector<ll> ComputeRollingHash(string s) {
    vector<ll> h(s.size(), 0);
    for (int i = 0; i < s.size(); ++i) {
        if (i != 0) h[i] = h[i - 1];
        h[i] = (h[i] + ((ll)s[i] * P[i]) % MOD) % MOD;
    }
    return h;
}

ll hash_fast(const vector<ll>& h, int L, int R) {
    if (L == 0) return h[R];
    ll ans = 0;
    ans = ((h[R] - h[L - 1]) % MOD + MOD) % MOD;
    ans = (ans * P_inv[L]) % MOD;
    return ans;
}

int main() {
    string T, P;
    ComputeP(MAXN);
    ComputePInverse(MAXN);
    while (getline(cin, P) && getline(cin, T)) {

        int n = T.size(), m = P.size();

        vector<ll> hash_pattern = ComputeRollingHash(P);
        vector<ll> hash_text = ComputeRollingHash(T);
        

        for (int i = 0; i + m - 1 <= n - 1; ++i) {
            bool matched = true;
            if (hash_fast(hash_pattern, 0, m - 1) != hash_fast(hash_text, i, i + m - 1)) matched = false;
            if (matched) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}