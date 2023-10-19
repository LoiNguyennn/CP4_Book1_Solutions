#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, ans = 0, sum = 0;
        cin >> n;
        vector<int> coin;
        for (int i = 0; i < n; ++i) {
            int d;
            cin >> d;
            coin.push_back(d);
        }
        for (int i = 0; i < coin.size() - 1; ++i) {
            if (sum + coin[i] < coin[i + 1]) {
                sum += coin[i];
                ++ans;
            }
        }
        cout << ans + 1 << endl; // the last coin always be taked if sum > last coin
    }
    return 0;
}