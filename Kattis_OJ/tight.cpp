#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int n, k;
ld memo[101][10];

ld f(int rem_n, int prev) {
    if (prev < 0 || prev > k)
        return 0;
    if (rem_n == 0)
        return 1;

    ld& ans = memo[rem_n][prev];
    if (ans > 0)
        return ans;
    ans = 0;
    ans += f(rem_n - 1, prev - 1) + f(rem_n - 1, prev) + f(rem_n - 1, prev + 1);
    return ans;
}

int main() {
    while (cin >> k >> n) {
        memset(memo, -1, sizeof(memo));
        ld omega = pow(k + 1, n);
        ld tight = 0;
        for (int i = 0; i <= k; ++i)
            tight += f(n - 1, i);
        cout << fixed << setprecision(9) << tight / omega * 100 << endl;
    }
    return 0;
}