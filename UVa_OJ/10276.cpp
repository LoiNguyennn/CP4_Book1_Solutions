#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        int top[n];
        memset(top, 0, sizeof(top));
        int ans = 1;
        while (true) {
            int i;
            for (i = 0; i < n; ++i) {
                int tmp = top[i] + ans;
                tmp = sqrt(tmp);
                if (tmp * tmp == top[i] + ans || top[i] == 0) {
                    top[i] = ans;
                    break;
                }
            }
            if (i == n) break;
            ++ans;
        }
        cout << ans - 1 << endl;
    }
    return 0;
}