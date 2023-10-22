#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int a, b;
    cin >> a;
    for (int i = 0; i < n - 1; ++i) {
        cin >> b;
        int divisor = gcd(a, b);
        cout << a / divisor << "/" << b / divisor << endl;
    }    
    return 0;
}