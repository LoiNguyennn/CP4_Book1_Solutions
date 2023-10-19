#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[10000];
ll n;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    n = 0;
    while (cin >> a[n]) {
        ++n;
        sort(a, a + n);
        if (n % 2 == 0) {
            cout << (a[n / 2] + a[n / 2 - 1]) / 2 << endl; 
        } else {
            cout << a[n / 2] << endl;
        }
    }
    return 0;
}