#include <bits/stdc++.h>

#define EPSILON 1e-8

using namespace std;

typedef long long ll;

int main() {
    ll D;
    cin >> D;

    for (ll a = sqrt(D); a <= (D + 1) / 2; ++a) {
        double b = sqrt(a * a - D);
        if (fabs(b - int(b)) <= EPSILON && b >= 0 && b <= (a - 1)) {
            cout << b << " " << a << endl;
            return 0;
        }
    }
    cout << "impossible\n";
    return 0;

}