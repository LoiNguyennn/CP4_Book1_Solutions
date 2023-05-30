#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n) {
		int a[n];
		for (int i = 0; i < n; ++i)
			cin >> a[i];

		int wavio[n];
		for (int i = 0; i < n; ++i)
			wavio[i] = 1;

		int LIS[n];
		int leng = 0;
		for (int i = 0; i < n; ++i) {
			int pos = lower_bound(LIS, LIS + leng, a[i]) - LIS;
			LIS[pos] = a[i];
			if (pos == leng)
				++leng;
			wavio[i] = pos + 1;
		}

		leng = 0;
		reverse(a, a + n);
		for (int i = 0; i < n; ++i) {
			int pos = lower_bound(LIS, LIS + leng, a[i]) - LIS;
			LIS[pos] = a[i];
			if (pos == leng)
				++leng;
			wavio[n - 1 - i] = min(wavio[n - 1 - i], pos + 1);
		}

		int ans = 1;
		for (int i = 0; i < n; ++i) 
			ans = max(ans, 2 * wavio[i] - 1);
		cout << ans << endl;
	}
	return 0;
}