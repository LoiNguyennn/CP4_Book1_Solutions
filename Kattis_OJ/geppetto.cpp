#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> s;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        s.insert({a, b});
    }

    int ans = 0;

    for (int mask = 0; mask < (1 << n); ++mask) {
        bool ok = true;
        for (auto x : s) {
            int a = x.first, b = x.second;
            if ((mask & (1 << a)) && (mask & (1 << b))) {
                ok = false;
                break;
            }
        }
        if (ok)
            ++ans;
    }
    cout << ans << endl;
    return 0;
}