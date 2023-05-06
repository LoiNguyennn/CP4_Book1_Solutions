#include <bits/stdc++.h>

using namespace std;

int f[300006];

int main() {
	set<int> bst;
	int n;
	cin >> n;
	long long ans = 0;
	int t;
	cin >> t;
	bst.insert(t);
	cout << ans << endl;
	for (int i = 1; i < n; ++i) {
		cin >> t;
		bst.insert(t);
		set<int>::iterator it = bst.find(t);
		int smaller = 0, larger = 0;
		int depth = 0;
		if (it == bst.begin()) {
			++it;
			larger = *it;
		} else if (it == --bst.end()) {
			--it;
			smaller = *it;
		} else {
			++it;
			larger = *it;
			--it;
			--it;
			smaller = *it;
		}
		depth = max(f[larger], f[smaller]) + 1;
		f[t] = depth;
		ans += 1ll * depth;
		cout << ans << endl;
	}
	return 0;
}