#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b, d;
        cin >> a >> b >> d;
        if (d % gcd(a, b) == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }    
    return 0;
}