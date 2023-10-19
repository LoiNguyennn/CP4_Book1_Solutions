#include <bits/stdc++.h>

using namespace std;

int memo[27][27][360];
int L, S;

int dp(int id, int rem_len, int rem_sum) {
    if (rem_len == 0 && rem_sum == 0) return 1;
    if (id > 26 || rem_len <= 0 || rem_sum <= 0) return 0;
    int& ans = memo[id][rem_len][rem_sum];
    if (ans != -1) return ans;
    if (rem_sum >= id)
        return ans = dp(id + 1, rem_len - 1, rem_sum - id) + dp(id + 1, rem_len, rem_sum);
    return ans = dp(id + 1, rem_len, rem_sum);
}

int main() {
    int testCase = 1;
    while (cin >> L >> S) {
        if (L == 0 && S == 0) break;

        if (L > 26 || S > 351) {
            cout << "Case " << testCase++ << ": 0\n";
            continue;
        }
        memset(memo, -1, sizeof(memo));
        cout << "Case " << testCase++ << ": " << dp(1, L, S) << endl;
    }
    return 0;
}