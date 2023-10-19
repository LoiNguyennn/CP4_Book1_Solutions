#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int paper[n + 1];
    paper[0] = paper[1] = 0;
    for (int i = 2; i <= n; ++i)
        cin >> paper[i];

    double len[n + 1];
    len[1] = 0.8408964152537146;
    
    for (int i = 2; i <= n; ++i) {
        len[i] = len[i - 1] / sqrt(2);
    }

    int need[n + 1];
    need[1] = 1;
    int i;
    for (i = 2; i <= n; ++i) {
        need[i] = 2 * need[i - 1];
        if (need[i] <= paper[i])
            break;
        need[i] -= paper[i];
    }
    if (i > n) {
        cout << "impossible\n";
    } else {
        double ans = 0;
        ans += need[i] * len[i] / 2.0;
        for (int idx = i - 1; idx >= 2; --idx) {
            ans += (need[idx] + paper[idx]) * len[idx] / 2.0;
        }
        cout << fixed << setprecision(11) << ans << endl;
    }
    return 0;
}