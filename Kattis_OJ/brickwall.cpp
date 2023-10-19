#include <bits/stdc++.h>

using namespace std;

int n, c1, c2, c3, len;
unordered_map<int, int> intersect;
int memo[301][301][301];

int dp(int k1, int k2, int k3) {
    int dist = k1 + k2 * 2 + k3 * 3;
    
    int& ans = memo[k1][k2][k3];
    if (ans != -1) return ans;

    if (dist == len) return ans = 1;
    if (dist > len) return ans = 0;
    if (intersect[dist]) return ans = 0;
    
    if (k1 < c1 && dp(k1 + 1, k2, k3)) {
        return ans = 1;
    }
    if (k2 < c2 && dp(k1, k2 + 1, k3)) {
        return ans = 1;
    }
    if (k3 < c3 && dp(k1, k2, k3 + 1)) {
        return ans = 1;
    }
    return ans = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> c1 >> c2 >> c3;
    memset(memo, -1, sizeof(memo));
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        len += x;
        intersect[len] = true;
    }

    if (dp(0, 0, 0)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}