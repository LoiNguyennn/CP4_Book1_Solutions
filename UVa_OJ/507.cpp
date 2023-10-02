#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; ++tc) {
        int s;
        cin >> s;
        int a[s - 1];
        for (int i = 0; i < s - 1; ++i)
            cin >> a[i];
            
        int ans = 0, sum = 0, i = 0, j = 0;
        int l = 0;
        for (int r = 0; r < s - 1; ++r) {
            sum += a[r];
            if (sum < 0) {
                l = r + 1;
                sum = 0;
            }
            if (sum > ans || sum == ans && r - l > j - i) {
                ans = sum;
                i = l;
                j = r;
            }
        }
        if (ans <= 0) {
            cout << "Route " << tc << " has no nice parts\n"; 
        } else {
            cout << "The nicest part of route " << tc << " is between stops " << i + 1  << " and " << j + 2 << endl;
        }
    }
    return 0;
}