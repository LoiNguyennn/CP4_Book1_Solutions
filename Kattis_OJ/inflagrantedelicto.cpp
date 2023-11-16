#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> a(n, 0);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        a[x] = i;
    }    

    vector<int> a1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        --x;
        a1.push_back(a[x]);
    }

    int k = 0;
    int LIS[n];

    for (int i = 0; i < a1.size(); ++i) {
        int pos = lower_bound(LIS, LIS + k, a1[i]) - LIS;
        LIS[pos] = a1[i];
        if (pos == k) ++k;
    }
    cout << 2 << " " << k + 1 << endl;
    return 0;
}