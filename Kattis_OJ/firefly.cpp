#include <bits/stdc++.h>

using namespace std;

int main() {
	int N, H;
	cin >> N >> H;
	vector<int> floor, ceiling;
	for (int i = 0; i < N / 2; ++i) {
		int t1, t2;
		cin >> t1 >> t2;
		floor.push_back(t1);
		ceiling.push_back(t2);
	}
	sort(floor.begin(), floor.end());
	sort(ceiling.begin(), ceiling.end());

	int min_hit = INT_MAX;
	int num_of_levels = 0;

	for (int h = 1; h <= H; ++h) {
		int num_hit_floor = floor.end() - lower_bound(floor.begin(), floor.end(), h);
		int num_hit_ceiling = ceiling.end() - lower_bound(ceiling.begin(), ceiling.end(), H - h + 1);
		if (num_hit_ceiling + num_hit_floor < min_hit) {
			min_hit = num_hit_ceiling + num_hit_floor;
			num_of_levels = 1;
		} else if (num_hit_ceiling + num_hit_floor == min_hit) {
			++num_of_levels;
		}
	}

	cout << min_hit << " " << num_of_levels << endl;
	return 0;
}