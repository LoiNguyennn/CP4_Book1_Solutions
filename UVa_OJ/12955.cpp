#include <bits/stdc++.h>

#define INF 1e9

using namespace std;

int f[10];
int memo[10][100001];

int dp(int id, int rem_n) {
    if (rem_n == 0)
        return 0;
    if (rem_n == 1)
        return 1;

    int& ans = memo[id][rem_n];
    if (ans != -1)
        return ans;
    if (rem_n >= f[id])
        return ans = min(min(dp(id + 1, rem_n - f[id]), dp(id, rem_n - f[id])) + 1, dp(id + 1, rem_n));
    return INF;
}

int main() {
    f[0] = f[1] = 1;
    for (int i = 2; i < 10; ++i)
        f[i] = f[i - 1] * i;
    memset(memo, -1, sizeof(memo));

    int n;
    while (cin >> n) {    
        cout << dp(1, n) << endl;
    }
    return 0;
}