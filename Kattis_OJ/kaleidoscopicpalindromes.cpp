#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fastPow(ll a, ll b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    ll x = fastPow(a, (b >> 1));
    if (b & 1) return x * x * a;
    return x * x;
}

bool isPalindrome(ll N, ll b) {
    ll n = N;
    ll len = log(n) / log(b) + 1;
    for (ll i = 1; i <= (len / 2); ++i) {
        ll l = n % b;
        ll r = (N / fastPow(b, len - i)) % b;
        if (l != r) return false;
        n /= b;
    }
    return true;
}

int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    ll ans = 0;
    for (ll i = a; i <= b; ++i) {
        bool valid = true;
        for (ll j = 2; j <= k; ++j) {
            if (!isPalindrome(i, j)) {
                valid = false;
                break;
            }
        }
        if (valid) ++ans;
    }
    cout << ans << endl;
    return 0;
}