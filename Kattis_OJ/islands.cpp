#include <bits/stdc++.h>

#define LSOne(S) ((S) & (-S))

using namespace std;

int main() {
    vector<int> contiguous;
    for (int i = 1; i < (1 << 10); ++i) {
        int most_sig = log2(i);
        int least_sig = log2(LSOne(i));
        if (most_sig - least_sig + 1 == __builtin_popcount(i))
            contiguous.push_back(i);
    }

    int TC;
    cin >> TC;
    while (TC--) {
        int k;
        cin >> k;
        int a[12];
        for (int i = 0; i < 12; ++i)
            cin >> a[i];

        int ans = 0;

        for (int i : contiguous) {
            int most_sig = log2(i);
            int least_sig = log2(LSOne(i));

            bool valid = true;
            int m = max(a[most_sig + 2], a[least_sig]);
            for (int i = least_sig + 1; i < most_sig + 2; ++i)
                if (a[i] <= m) {
                    valid = false;
                    break;
                }
            if (valid)
                ++ans;
        }
        cout << k << " " << ans << endl;
    }
    return 0;
}