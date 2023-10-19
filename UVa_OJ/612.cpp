#include <bits/stdc++.h>

using namespace std;

void Merge(pair<int, string> a[], int l, int r) {
    int m = (l + r) / 2;
    int n1 = m - l + 1;
    int n2 = r - m;
    pair<int, string> L[n1], R[n2];
    for (int i = 0; i < n1; ++i)
        L[i] = a[l + i];
    for (int i = 0; i < n2; ++i)
        R[i] = a[l + n1 + i];

    int i = 0, j = 0, id = l;
    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first)
            a[id++] = L[i++];
        else
            a[id++] = R[j++];
    }
    while (i < n1)
        a[id++] = L[i++];
    while (j < n2)
        a[id++] = R[j++];
}

void MergeSort(pair<int, string> a[], int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    Merge(a, l, r);
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;
        pair<int, string> a[m];
        for (int i = 0; i < m; ++i) {
            string s;
            int numInversion = 0;
            cin >> s;
            for (int j = 0; j < n; ++j)
                for (int k = j + 1; k < n; ++k)
                    if (s[j] > s[k]) ++numInversion;
            a[i] = make_pair(numInversion, s);
        }
        MergeSort(a, 0, m - 1);
        for (int i = 0; i < m; ++i)
            cout << a[i].second  << endl;
        if (TC) cout << endl;
    }
    return 0;
}