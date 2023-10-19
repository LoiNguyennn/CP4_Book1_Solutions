#include <iostream>
#include <cstring>

#define MOD int(1e9 + 7)

using namespace std;

int memo[105][10005];
int n, w, h;


int dp(int pos, int len) {
    if (len < 0) return 0;
    if (pos == w) return 1;

    int& ans = memo[pos][len];
    if (ans != -1)
        return ans;

    ans = 0;
    for (int i = 0; i <= h; ++i) {
        ans += dp(pos + 1, len - i);
        ans %= MOD;
    }
    
    return ans;
}

int main() {
    cin >> n >> w >> h;
    memset(memo, -1, sizeof(memo));

    int ans = dp(0, n);
    for (int i = 0; i <= h; ++i) {
        if (i * w <= n)
            --ans;
    }

    cout << ans << endl;
    return 0;
}