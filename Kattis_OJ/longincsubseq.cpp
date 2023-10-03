#include <bits/stdc++.h>

using namespace std;

vector<int> a, L, L_id, p;

void printLIS(int i) {
    if (p[i] == -1) {
        cout << i << " ";
        return;
    }
    printLIS(p[i]);
    cout << i << " ";
}

int main() {
    int n;
    while (cin >> n) {
        a.assign(n, 0);
        for (int i = 0; i < n; ++i) cin >> a[i];

        L.assign(n, 0);
        L_id.assign(n, 0);
        p.assign(n, -1);

        int k = 0, LIS_end = 0;

        for (int i = 0; i < n; ++i) {
            int pos = lower_bound(L.begin(), L.begin() + k, a[i]) - L.begin();
            L[pos] = a[i];
            L_id[pos] = i;
            p[i] = (pos == 0) ? -1 : L_id[pos - 1];
            if (pos == k) {
                ++k;
                LIS_end = i;
            } 
        }

        cout << k << endl;
        printLIS(LIS_end);
        cout << endl;
    }
    return 0;
}