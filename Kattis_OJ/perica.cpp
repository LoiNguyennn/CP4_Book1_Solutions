#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll memo[51][100001];
const int MOD = int(1e9 + 7);

ll C(ll k, ll n) {
    if (k == 0 || k == n) return 1;
    if (k == 1) return n;
    if (memo[k][n] != -1) return memo[k][n];
    return memo[k][n] = (C(k - 1, n - 1) + C(k, n - 1)) % MOD;
}

int main() {
    memset(memo, -1, sizeof(memo));
    int n, k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);

    ll ans = 0;
    for (int i = k - 1; i < n; ++i) {
        ans += a[i] * C(k - 1, i);
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}