#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    while (cin >> n) {
        if (n == 1) {
            cout << "1\n";
            continue;
        }
        int ans = 1, cur = 10;
        n *= 9;
        while (cur != 1) {
            ++ans;
            cur *= 10;
            cur %= n;
        }
        cout << ans << endl;
    }    
    return 0;
}