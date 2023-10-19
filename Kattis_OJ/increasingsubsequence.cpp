#include <bits/stdc++.h>

using namespace std;

void printLIS(int par[], int a[], int i) {
    if (par[i] == -1) {
        cout << a[i] << " ";
        return;
    }
    printLIS(par, a, par[i]);
    cout << a[i] << " ";
}

int main() {
    int n;
    while (cin >> n && n) {
        int a[n], LIS[n], LIS_idx[n], par[n];
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            LIS[i] = 1;
            par[i] = -1;
        }

        int leng = 0, lis_end = 0;
        for (int i = 0; i < n; ++i) {
            int pos = lower_bound(LIS, LIS + leng, a[i]) - LIS;
            LIS[pos] = a[i];
            LIS_idx[pos] = i;
            if (pos)
                par[i] = LIS_idx[pos - 1];
            if (pos == leng) {
                ++leng;
                lis_end = i;
            } else if (pos == leng - 1) {
                lis_end = i;
            }
        }
        cout << leng << " ";
        printLIS(par, a, lis_end);
        cout << endl;
    }
    return 0;
}