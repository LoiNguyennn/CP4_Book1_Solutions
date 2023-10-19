#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    while (cin >> n >> k) {
        int ans = n;
        while (n >= k) {
            n -= k - 1;
            ++ans;
        }
        cout << ans << endl;
    }
    return 0;
}