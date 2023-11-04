#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll memo[101][101];

ll C(ll k, ll n) {
    if (k == 0 || k == n) return 1;
    if (k == 1) return n;
    if (memo[k][n] != -1) return memo[k][n];
    return memo[k][n] = C(k - 1, n - 1) + C(k, n - 1);
}

int main() {
    memset(memo, -1, sizeof(memo));
    ll k, n;
    while (cin >> n >> k) {
        if (k == 0 && n == 0) break;
        cout << n << " things taken " << k << " at a time is " << C(k, n) << " exactly.\n";
    }
    return 0;
}