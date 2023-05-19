#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int TC;
	cin >> TC;
	int a, b;
	while (TC--) {
		vector<pair<int, int>> v;
		while (cin >> a >> b) {
			if (a == 0 && b == 0) break;
			v.push_back({a, b});
		} 
		sort(v.begin(), v.end(), cmp);

		vector<pair<int, int>> ans;
		ans.push_back(v[0]);


		for (int i = 1; i < v.size(); ++i) {
			if (v[i].first >= ans.rbegin()->second)
				ans.push_back(v[i]);
		}
		cout << ans.size() << endl;
	}
	return 0;
}