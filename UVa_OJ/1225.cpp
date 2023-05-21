#include <bits/stdc++.h>

using namespace std;

int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		int n;
		cin >> n;
		unordered_map<int, int> mp;
		for (int i = 1; i <= n; ++i) {
			int t = i;
			while (t) {	
				++mp[t % 10];
				t /= 10;
			}
		}
		for (int i = 0; i <= 8; ++i) {
			cout << mp[i] << " ";
		}
		cout << mp[9] << endl;
	}
	return 0;
}