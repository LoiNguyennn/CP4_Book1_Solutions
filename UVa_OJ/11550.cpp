#include <bits/stdc++.h>

using namespace std;

bool solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> AL(m); // edge: vertex1, vertex2
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int t;
			cin >> t;
			if (t)
				AL[j].push_back(i);
		}	
	}
	for (int i = 0; i < m; ++i)
		if (AL[i].size() != 2)
			return false;

	set<pair<int, int>> vertices;
	for (int i = 0; i < m; ++i) {
		auto it = vertices.find({AL[i][0], AL[i][1]});
		if (it != vertices.end())
			return false;
		vertices.insert({AL[i][0], AL[i][1]});
	}
	return true;
}

int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		if (solve()) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
	return 0;
}