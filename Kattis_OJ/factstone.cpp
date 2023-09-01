#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
    int n;
    ll num_bits[201];
    ll cur_bit = 4, cnt = 0;
    for (int i = 0; i < 201; ++i) {
        num_bits[i] = cur_bit;
        ++cnt;
        if (cnt == 10) {
            cnt = 0;
            cur_bit = cur_bit << 1;
        }
    }

    while (cin >> n) {
        if (n == 0) break;
        n -= 1960;
        int ans = 1;
        double logans = log2(1);
        while (logans < num_bits[n]) {
            ++ans;
            logans += log2(ans);
        }
        --ans;
        cout << ans << endl;
    }
    return 0;
}