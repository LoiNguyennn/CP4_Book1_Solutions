#include <bits/stdc++.h>

using namespace std;

long long numInversion;

void Merge(int a[], int l, int r) {
    int m = (l + r) / 2;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; ++i)
        L[i] = a[l + i];
    for (int i = 0; i < n2; ++i)
        R[i] = a[l + n1 + i];

    int i = 0, j = 0, id = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[id++] = L[i++];
        } else {
            a[id++] = R[j++];
            numInversion += n1 - i;
        }
    }
    while (i < n1)
        a[id++] = L[i++];
    while (j < n2)
        a[id++] = R[j++];
}

void MergeSort(int a[], int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    MergeSort(a, l, m);
    MergeSort(a, m + 1, r);
    Merge(a, l, r);
}

int main() {
    int n;
    cin >> n;     
    int a[n];
    numInversion = 0;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    MergeSort(a, 0, n - 1);
    cout << numInversion << endl;

    return 0;
}