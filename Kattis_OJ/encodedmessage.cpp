#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        string s;
        cin >> s;

        int n = sqrt(s.size());
        char a[n][n];

        int idx = 0;
        for (int j = 0; j < n; ++j) {
            for (int i = n - 1; i >= 0; --i) {
                a[i][j] = s[idx++];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) 
                cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}