#include <bits/stdc++.h>

using namespace std;

int main() {
	int numRow, numCol;
	while (cin >> numRow >> numCol) {
		vector<vector<pair<int, int>>> AL(numRow);
		for (int i = 0; i < numRow; ++i) {
			int n;
			cin >> n;
			if (n == 0) continue;
			int t;
			for (int j = 0; j < n; ++j) {
				cin >> t;
				AL[i].push_back(make_pair(--t, 0));
			}
			for (int j = 0; j < n; ++j) {
				cin >> t;
				AL[i][j].second = t;
			}
		}
		vector<vector<pair<int, int>>> ALres(numCol);
		for (int i = 0; i < numRow; ++i) {
			for (pair<int, int> x : AL[i]) {
				// aij will be swapped with aji in transposed matrix, it's a little bit confused
				ALres[x.first].push_back(make_pair(i, x.second));
			}
		}

		cout << numCol << " " << numRow << "\n";
		for (int i = 0; i < numCol; ++i) {
			int n = ALres[i].size();
			cout << n;
			if (n == 0) {
				cout << "\n\n";
				continue;
			} else {
				cout << " ";
			}
			for (int j = 0; j < n - 1; ++j)
				cout << ALres[i][j].first + 1 << ' ';
			cout << ALres[i][n - 1].first + 1 << '\n';
			
			for (int j = 0; j < n - 1; ++j)
				cout << ALres[i][j].second << ' ';
			cout << ALres[i][n - 1].second << '\n';
		}
	}
	return 0;
}