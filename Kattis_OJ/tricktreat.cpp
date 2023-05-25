#include <bits/stdc++.h>

using namespace std;

vector<pair<double, double>> points;

double dist(double x, double y, double x2) {
	return sqrt((x - x2) * (x - x2) + y * y);
}

double F(double x) {
	double max_dist = 0;
	for (auto i : points) 
		max_dist = max(max_dist, dist(i.first, i.second, x));
	return max_dist;
}

int main() {
	freopen("input.txt", "r", stdin);
	int n;
	while (cin >> n && n) {
		for (int i = 0; i < n; ++i) {
			double x, y;
			cin >> x >> y;
			points.push_back({x, y});
		}

		double lo = -1e7, hi = 1e7;
		for (int i = 0; i < 150; ++i) {
			double delta = (hi - lo) / 3;
			double m1 = lo + delta;
			double m2 = hi - delta;

			if (F(m1) <= F(m2)) {
				hi = m2;
			} else {
				lo = m1;
			}
		}
		cout << fixed << setprecision(12) << lo << " " << F(lo) << endl;
		points.clear();
	}
	return 0;
}