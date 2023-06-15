#include <bits/stdc++.h>

using namespace std;

int LessThan(string a, string b) {
	if (a[0] != b[0]) return a[0] < b[0];
	if (a[1] != b[1]) return a[1] < b[1];
	return -1;
}

void Merge(string a[], int l, int r) {
	int m = (l + r) / 2;
	int n1 = m - l + 1;
	int n2 = r - m;
	string L[n1], R[n2];
	for (int i = 0; i < n1; ++i)
		L[i] = a[l + i];
	for (int j = 0; j < n2; ++j)
		R[j] = a[l + n1 + j];

	int i = 0, j = 0, id = l;
	while (i < n1 && j < n2) {
		int check = LessThan(L[i], R[j]);
		if (check == 1 || check == -1) {
			a[id++] = L[i++];
		} else {
			a[id++] = R[j++];
		}
	}

	while (i < n1)
		a[id++] = L[i++];
	while (j < n2)
		a[id++] = R[j++];

}

void MergeSort(string a[], int l, int r) {
	if (l >= r) return;
	int m = (l + r) / 2;
	MergeSort(a, l, m);
	MergeSort(a, m + 1, r);
	Merge(a, l, r);
}

int main() {
	int n;
	while (cin >> n) {
		string a[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		MergeSort(a, 0, n - 1);

		for (int i = 0; i < n; ++i)
			cout << a[i] << endl;
		cout << endl;
	}
	return 0;
}