#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            if (j > 0)
                a[i][j] += a[i][j - 1];
        }

    int ans = INT_MIN;
    for (int l = 0; l < n; ++l) {
        for (int r = l; r < n; ++r) {
            int sum = 0;
            for (int row = 0; row < n; ++row) {
                sum += a[row][r];
                if (l > 0) 
                    sum -= a[row][l - 1]; 
                ans = max(ans, sum);
                if (sum < 0) sum = 0;
            }
        }
    }

    cout << ans << endl;
    return 0;
}