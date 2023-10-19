#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ll memo[70][70][2];

ll dp(int id, int rem_s, int prev) {
    if (id < 0 || rem_s < 0)
        return 0;
    else if (rem_s == 0 && id == 0)
        return 1;

    if (memo[id][rem_s][prev] != -1) return memo[id][rem_s][prev];
    if (prev)
        return memo[id][rem_s][prev] = dp(id - 1, rem_s, 0) + dp(id - 1, rem_s - 1, 1); // not lock and lock
    return memo[id][rem_s][prev] = dp(id - 1, rem_s, 0) + dp(id - 1, rem_s, 1); // not lock and lock
}

int main() {
    int n, s;
    memset(memo, -1, sizeof(memo));
    while (scanf("%d %d", &n, &s)) {
        if (n < 0) break;
        printf("%lld\n", dp(n, s, 1));
    }
    return 0;
}