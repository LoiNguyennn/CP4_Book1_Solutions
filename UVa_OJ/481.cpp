#include <bits/stdc++.h>

using namespace std;

void printLIS(int i, vector<int>& parent, vector<int>& a) {
	if (parent[i] == -1) {
		cout << a[i] << endl;
		return;
	}
	printLIS(parent[i], parent, a);
	cout << a[i] << endl;
}

int main() {
	vector<int> a;
	int t;
	while (cin >> t) {
		a.push_back(t);
	}

	vector<int> parent(a.size(), -1);
	vector<int> LIS(a.size(), 0);
	vector<int> LIS_ID(a.size(), 0);

	int leng = 0, lis_end = 0;
	for (int i = 0; i < a.size(); ++i) {
		int pos = lower_bound(LIS.begin(), LIS.begin() + leng, a[i]) - LIS.begin();
		LIS[pos] = a[i];
		LIS_ID[pos] = i;
		if (pos)
			parent[i] = LIS_ID[pos - 1];
		if (pos == leng) {
			++leng;
			lis_end = i;
		}
	}
	cout << leng << endl;
	cout << "-" << endl;
	printLIS(lis_end, parent, a);
	return 0;
}