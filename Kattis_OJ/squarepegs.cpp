#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<double> plot;
	vector<double> circle;
	int t;
	for (int i = 0; i < n; ++i) {
		cin >> t;
		plot.push_back(t);
	}
	for (int i = 0; i < m; ++i) {
		cin >> t;
		circle.push_back(t);
	}
	for (int i = 0; i < k; ++i) {
		cin >> t;
		circle.push_back(t / sqrt(2));
	}
	sort(plot.begin(), plot.end());
	sort(circle.begin(), circle.end());

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = circle.size() - 1; j >= 0; --j) {
			if (circle[j] < 0)
				continue;
			if (circle[j] < plot[i]) {
				++ans;
				circle[j] = -1;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}