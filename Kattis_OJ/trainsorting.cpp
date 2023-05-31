#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	reverse(a, a + n);

	int LIS[n], LDS[n];
	for (int i = 0; i < n; ++i) {
		LIS[i] = 1;
		LDS[i] = 1;
	}

	for (int i = 1; i < n; ++i) {
		int max_LIS = 1, max_LDS = 1;
		for (int j = 0; j < i; ++j) {
			if (a[j] < a[i])
				max_LIS = max(max_LIS, LIS[j] + 1);
			if (a[j] > a[i])
				max_LDS = max(max_LDS, LDS[j] + 1);
		}
		LIS[i] = max_LIS;
		LDS[i] = max_LDS;
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(LIS[i] + LDS[i] - 1, ans);
	}
	cout << ans << endl;
	return 0;
}