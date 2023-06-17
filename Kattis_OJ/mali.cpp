#include <bits/stdc++.h>

using namespace std;

int match(vector<int> a, vector<int> b) {
	int i = 0, j = 100, ans = 0;
	while (true) {
		while (i <= 100 && a[i] == 0) ++i;
		while (j >= 0 && b[j] == 0) --j;
		if (i > 100 || j < 0) break;
		ans = max(ans, i + j);
		int f = min(a[i], b[j]);
		a[i] -= f;
		b[j] -= f;
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(101, 0), b(101, 0);
	for (int i = 0; i < n; ++i) {
		int t1, t2;
		cin >> t1 >> t2;
		++a[t1]; ++b[t2];
		cout << match(a, b) << endl;
	}
	return 0;
}