#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;
    ll cans[n];
    for (int i = 0; i < n; ++i)
        cin >> cans[i];
    sort(cans, cans + n);
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        ll t;
        cin >> t;
        ans += *lower_bound(cans, cans + n, t) - t;
    }
    cout << ans << endl;
    return 0;
}