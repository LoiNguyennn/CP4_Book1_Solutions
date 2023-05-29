#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, p;
	cin >> n >> p;
	int sum = 0, ans = 0;
	for (int i = 0; i < n; ++i) {
		int t;
		cin >> t;
		sum += t - p;
		ans = max(sum, ans);
		if (sum < 0)
			sum = 0;
	}
	cout << ans << endl;
	return 0;
}