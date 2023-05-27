#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> activity;
	multiset<int> latest;
	for (int i = 0; i < n; ++i) {
		int s, f;
		cin >> s >> f;
		activity.push_back({f, s});
	}
	sort(activity.begin(), activity.end());
	
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (latest.empty()) {
			++ans;
			latest.insert(activity[i].first);
		} else {
			int start = activity[i].second;
			int finish = activity[i].first;
			auto it = latest.lower_bound(start);
			if (it == latest.end())
				--it;
			while (it != latest.begin() && *it >= start)
				--it;
			if (it == latest.begin() && *it >= start) {
				if (latest.size() < k) {
					latest.insert(finish);
					++ans;
				}
				continue;
			}
			++ans;
			latest.erase(it);
			latest.insert(activity[i].first);

		}
	}
	cout << ans << endl;
	return 0;
}