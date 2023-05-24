#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n) {
		vector<int> list1, list2;
		list1.reserve(n);
		list2.reserve(n);
		vector<int> tmp;
		tmp.reserve(n);
		int t;
		for (int i = 0; i < n; ++i) {
			cin >> t;
			list1.push_back(t);
			tmp.push_back(t);
		}
		for (int i = 0; i < n; ++i) {
			cin >> t;
			list2.push_back(t);
		}
		sort(list1.begin(), list1.end());
		sort(list2.begin(), list2.end());
		for (int i = 0; i < tmp.size(); ++i) {
			int idx = lower_bound(list1.begin(), list1.end(), tmp[i]) - list1.begin();
			cout << list2[idx] << endl;
		}
		cin >> n;
		if (n)
			cout << endl;
	}
	return 0;
}