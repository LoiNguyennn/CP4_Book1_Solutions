#include <bits/stdc++.h>

#define EPS 1e-6

using namespace std;

int main() {
	int n, d;
	int TC_counter = 1;
	while (cin >> n >> d) {
		if (n == 0 && d == 0)
			break;
		vector<pair<double, double>> segment;
		
		bool possible = true;
		for (int k = 0; k < n; ++k) {
			int i, j;
			cin >> i >> j;
			if (j > d) 
				possible = false;
			else {
				double x_left = double(i) - sqrt(d * d - j * j);
				double x_right = double(i) + sqrt(d * d - j * j);
				segment.push_back({x_left, x_right});
			}
		}

		if (!possible) {
			cout << "Case " << TC_counter++ << ": -1\n";
			continue;
		}

		sort(segment.begin(), segment.end());

		int ans = 0;
		double covered = -1e10;
	
		int i = 0;
		while (i < n) {
			if (segment[i].first > covered) {
				covered = segment[i].second;		
				++ans;
			}
			else
				covered = min(covered, segment[i].second);
			++i;
		}
		cout << "Case " << TC_counter++ << ": " << ans << endl;
	}
	return 0;
}