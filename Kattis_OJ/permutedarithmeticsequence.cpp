#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        bool arithmetic = true, permuted_arithmetic = true;
        int d = a[0] - a[1];
        for (int i = 1; i < n - 1; ++i) {
            if (a[i] - a[i + 1] != d) {
                arithmetic = false;
                break;
            }
        }
        if (arithmetic) {
            cout << "arithmetic\n";
            continue;
        } 

        sort(a, a + n);
        d = a[0] - a[1];
        for (int i = 1; i < n - 1; ++i) {
            if (a[i] - a[i + 1] != d) {
                permuted_arithmetic = false;
                break;
            }
        }

        if (permuted_arithmetic) {
            cout << "permuted arithmetic\n";
        } else {
            cout << "non-arithmetic\n";
        }
    }
    return 0;
}