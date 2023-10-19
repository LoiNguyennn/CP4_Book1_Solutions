#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;

ll memo[86][2];

ll dp(int level, int prev) {
    if (level == n) 
        return 1;
    if (level > n) 
        return 0;

    ll& ans = memo[level][prev];
    if (ans != -1) return ans;

    if (prev)
        return ans = dp(level + 1, 1) + dp(level + 1, 0);
    return ans = dp(level + 1, 1);
}

int main() {
    while (cin >> n && n) {
        memset(memo, -1, sizeof(memo));
        if (n == 1) {
            cout << "1\n";
        } else {
            cout << dp(2, 1) << endl;
        }
    }
    return 0;
}