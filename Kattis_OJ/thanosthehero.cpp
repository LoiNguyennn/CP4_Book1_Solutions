#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	long long a[n];
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	long long ans = 0;
	bool valid = true;

	for (int i = n - 1; i >= 1; --i) {
		if (a[i] == 0) {
			valid = false;
			break;
		}
		if (a[i - 1] >= a[i]) {
			ans += a[i - 1] - (a[i] - 1);
			a[i - 1] = a[i] - 1;
		}
	}
	if (valid)
		cout << ans << endl;
	else 
		cout << "1" << endl;
	return 0;
}