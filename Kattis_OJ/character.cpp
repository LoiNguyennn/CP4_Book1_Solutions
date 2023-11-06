#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll memo[31][31];

ll C(ll k, ll n) {
    if (k == 0 || k == n) return 1;
    if (k == 1) return n;
    if (memo[k][n] != -1) return memo[k][n];
    return memo[k][n] = C(k - 1, n - 1) + C(k, n - 1);
}

int main() {
    int n;
    cin >> n;
    memset(memo, -1, sizeof(memo));
    if (n < 2) {
        cout << "0\n";
    } else if (n == 2) {
        cout << "1\n";
    } else {
        int ans = n * (n - 1) / 2;
        for (int i = 3; i <= n; ++i)
            ans += C(i, n);
        cout << ans << endl;
    }   
    return 0;
}