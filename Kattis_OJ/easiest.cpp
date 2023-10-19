#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll sumDigits(ll n) {
    ll ans = 0;
    while (n) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
    ll n;
    while (cin >> n && n) {
        ll i = 11;
        ll sum = sumDigits(n);
        while (sumDigits(i * n) != sum) 
            ++i;
        cout << i << endl;
    }
    return 0;
}