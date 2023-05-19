#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<pair<int, int>> r(3);
	for (int i = 0; i < 3; ++i)
		cin >> r[i].first >> r[i].second;

	for (int mask = 0; mask < (1 << 3); ++mask) {
		vector<pair<int, int>> tmp = r;
		for (int i = 0; i < 3; ++i)
			if (mask & (1 << i))
				swap(tmp[i].first, tmp[i].second);
		
		int width = tmp[0].second;
		if (tmp[1].second == width && tmp[2].second == width && tmp[0].first + tmp[1].first + tmp[2].first == width) {
			cout << "YES\n";
			return 0;
		}
	}

	int a[3] = {0, 1, 2};
	do {
		for (int mask = 0; mask < (1 << 3); ++mask) {
			vector<pair<int, int>> tmp = r;
			
			for (int i = 0; i < 3; ++i)
				if (mask & (1 << i))
					swap(tmp[i].first, tmp[i].second);

			int high = tmp[a[2]].first;
			if (tmp[a[0]].first + tmp[a[1]].first == high && tmp[a[0]].second == tmp[a[1]].second
				&& tmp[a[0]].second + tmp[a[2]].second == high) {
				cout << "YES\n";
				return 0;
			}
		}
	} while (next_permutation(a, a + 3));
	cout << "NO\n";
	return 0;
}