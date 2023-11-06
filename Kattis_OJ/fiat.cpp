#include <bits/stdc++.h>

#define MOD int(1e9 + 7)

using namespace std;

typedef long long ll;

ll cat[100005];

ll ExtendedEuclid(ll a, ll b, ll &x, ll &y) {
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

ll modInverse(ll b, ll m) {
    ll x, y;
    ll d = ExtendedEuclid(b, m, x, y);
    if (d != 1) return -1; 
    return ((x % m) + m) % m;
}

int main() {
    int n;
    cin >> n;
    cat[0] = 1;

    for (int i = 0; i <= n; ++i)
        cat[i + 1] = ((4 * i + 2) % MOD * cat[i] % MOD * modInverse(i + 2, MOD)) % MOD;
   
    cout << cat[n] << endl;
    return 0;
}