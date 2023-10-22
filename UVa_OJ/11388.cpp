#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC;
    while (TC--) {
        ll G, L;
        cin >> G >> L;
        ll mul = G * L;

        bool found = false;
        for (ll a = G; a <= L; a += G) {
            if (L % a) continue;
            if (mul % a == 0) {
                cout << a << " " << mul / a << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "-1\n";
        }
    }   

    return 0;
}