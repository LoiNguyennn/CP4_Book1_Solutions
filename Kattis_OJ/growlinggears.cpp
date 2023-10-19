#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        int gear = 0, torque = 0;
        for (int i = 0; i < n; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            if (b * b / (4.0 * a) + c > torque) {
                torque = b * b / (4.0 * a) + c;
                gear = i + 1;
            }
        }
        cout << gear << endl;
    }
    return 0;
}