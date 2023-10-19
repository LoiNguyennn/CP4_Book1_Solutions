#include <bits/stdc++.h>

using namespace std;

int rat[1025][1025];

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int d, n;
        cin >> d >> n;
        memset(rat, 0, sizeof(rat));

        for (int l = 0; l < n; ++l) {
            int a, b, p;
            cin >> a >> b >> p;
            for (int i = a - d; i <= a + d; ++i) {
                for (int j = b - d; j <= b + d; ++j) {
                    if (i >= 0 && i < 1025 && j >= 0 && j < 1025)
                        rat[i][j] += p;
                }
            }
        }

        int x = 0, y = 0, max_size = 0;
        for (int i = 0; i < 1025; ++i) {
            for (int j = 0; j < 1025; ++j) {
                if (rat[i][j] > max_size) {
                    max_size = rat[i][j];
                    x = i;
                    y = j;
                }
            }
        }
        cout << x << " " << y << " " << max_size << "\n";
    }
    return 0;
}