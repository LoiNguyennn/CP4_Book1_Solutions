#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, b;
	cin >> n >> b;
	int idx;
	int a[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		if (a[i] == b)
			idx = i;
	}
	map<int, int> mp;
	++mp[0];
	int diff = 0;
	int ans = 0;
	for (int i = idx + 1; i < n; ++i) {
		if (a[i] > b)
			++diff;
		else 
			--diff;
		++mp[diff];
	}
	ans += mp[0];
	diff = 0;
	for (int i = idx - 1; i >= 0; --i) {
		if (a[i] > b)
			++diff;
		else
			--diff;
		ans += mp[-diff];
	}
	cout << ans << endl;
	return 0;
}