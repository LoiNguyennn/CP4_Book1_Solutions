#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    while (cin >> n && n) {
        multiset<ll> s;
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            int t;
            cin >> t;
            for (int j = 1; j <= t; ++j) {
                ll m;
                cin >> m;
                s.insert(m);
            }
            ans += *s.rbegin() - *s.begin();
            s.erase(s.begin());
            s.erase(--s.end());
        }        
        cout << ans << endl;
    }
    return 0;
}