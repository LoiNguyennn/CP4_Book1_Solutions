#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, e;
        cin >> n >> e;
        int p, q;
        bool solved = false;
        for (p = 2; p < 1000 && !solved; ++p) {
            for (q = 2; q < 1000 && !solved; ++q) {
                if (p * q == n) {
                    solved = true;
                    break;
                }
            }
        }
        --p;

        long long phi = (p - 1) * (q - 1);

        for (long long d = 2; d < phi; ++d) {
            if ((d * e) % phi == 1) {
                cout << d << endl;
                break;
            }
        }
    }
    return 0;
}