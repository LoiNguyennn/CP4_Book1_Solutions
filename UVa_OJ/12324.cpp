#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
ll trip[100], sphere[100];
ll memo[101][10001];

ll dp(int id, int s) { // id, no spheres produced in the preceding trip
    // give sphere for this trip or not?
    if (id == n - 1)
        return (s > 0) ? (trip[id] / 2) : trip[id];

    ll& ans = memo[id][s];
    if (ans != -1)
        return ans;
    if (s > 0)
        return ans = min(dp(id + 1, s + sphere[id] - 1) + trip[id] / 2, dp(id + 1, s + sphere[id]) + trip[id]);
    return ans = dp(id + 1, s + sphere[id]) + trip[id];
}

int main() {
    while (cin >> n && n ) {
        memset(memo, -1, sizeof(memo));
        for (int i = 0; i < n; ++i)
            cin >> trip[i] >> sphere[i];
        cout << dp(0, 0) << endl;
    }
    return 0;
}