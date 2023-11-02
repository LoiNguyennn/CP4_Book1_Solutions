#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    while (cin >> n && n) {
        if (n == 3) {
            cout << 4 << endl;
            continue;
        }
        if (n < 7) {
            cout << "No such base\n";
            continue;
        }


        n -= 3;
        ll ans = 1e12;
        for (ll i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                if (i >= 4)
                    ans = min(ans, i);
                if (n / i >= 4)
                    ans = min(ans, n / i);
            }
        }


        cout << ans << endl;
    }    
    return 0;
}