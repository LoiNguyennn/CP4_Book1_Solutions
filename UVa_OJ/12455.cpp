#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, p;
        cin >> n >> p;
        bool sol = false;
        int bars[p];
        for (int i = 0; i < p; ++i)
            cin >> bars[i];
        for (int mask = 0; mask < (1 << p); ++mask) {
            int sum = 0;
            for (int j = 0; j < p && sum < n; ++j)
                if (mask & (1 << j))
                    sum += bars[j];

            if (sum == n) {
                sol = true;
                break;
            }
        }
        if (sol) 
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}