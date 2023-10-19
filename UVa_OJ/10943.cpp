#include <bits/stdc++.h>

#define MOD 1000000

using namespace std;

typedef long long ll;

ll memo[110][110];

ll n, k;

ll dp(ll remN, ll remK) {
    if (remK == 1) return 1;

    ll& ans = memo[remN][remK];
    if (ans != -1) return ans;

    ans = 0;
    for (int i = 0; i <= remN; ++i)
        ans += dp(remN - i, remK - 1) % MOD;
    return ans % MOD;
}

int main() {
    while (cin >> n >> k) {
        if (n == 0 && k == 0)
            break;
        memset(memo, -1, sizeof(memo));
        cout << dp(n, k) % MOD << endl;
    }
    return 0;
}