#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int TC;
    cin >> TC;
    cin.ignore();

    while (TC--) {
        int n;
        cin >> n;
        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ll x;
            cin >> x;
            ans += x;
            ans %= n;
        }
        if (ans == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}