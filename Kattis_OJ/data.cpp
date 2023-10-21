#include <bits/stdc++.h>

#define MAX_N 14004
#define LSOne(S) ((S) & (-S))


using namespace std;

int memo[(1 << 14)][14];
int numDiffPF[MAX_N], s[14];
int n;

const int INF = -(int)1e7;

int dp(int bm, int c) {
    if (c >= n) 
        return (bm == 0) ? 0 : INF;
    int& ans = memo[bm][c];
    if (ans != -1) return ans;

    int mask = bm;
    vector<int> available;
    while (mask > 0) {
        int lsone = LSOne(mask);
        available.push_back(__builtin_ctz(lsone));
        mask -= lsone;
    }

    int full_mask = (1 << available.size()) - 1;
    
    ans = 0;
    for (int i = 0; i <= full_mask; ++i) {
        int next_mask = bm, total = 0;
        mask = i;
        while (mask > 0) {
            int lsone = LSOne(mask);
            int id = available[__builtin_ctz(lsone)];
            total += s[id];
            next_mask &= ~(1 << id);
            mask -= lsone;
        }
        ans = max(ans, dp(next_mask, c + 1) + numDiffPF[total]);
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];

    memset(numDiffPF, 0, sizeof(numDiffPF));
    for (int i = 2; i <= MAX_N; ++i) 
        if (numDiffPF[i] == 0) 
            for (int j = i; j <= MAX_N; j += i) 
                ++numDiffPF[j];
        
    memset(memo, -1, sizeof(memo));
    cout << dp((1 << n) - 1, 0) << endl;
    return 0;
}