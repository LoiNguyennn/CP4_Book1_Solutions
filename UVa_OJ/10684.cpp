#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		int ans = INT_MIN;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int t;
			cin >> t;
			sum += t;
			ans = max(sum, ans);
			if (sum < 0)
				sum = 0;
		}
		if (ans > 0)
			cout << "The maximum winning streak is " << ans << ".\n";
		else
			cout << "Losing streak.\n";
	}
	return 0;
}