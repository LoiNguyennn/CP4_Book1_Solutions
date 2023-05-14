#include <bits/stdc++.h>

using namespace std;

int p[500001], s[500001];

int find_set(int i) {
	if (p[i] == i) return i;
	return p[i] = find_set(p[i]);
}

void union_set(int i, int j) {
	int x = find_set(i), y = find_set(j);
	if (x == y) return;
	if (s[x] > s[y]) swap(x, y);
	p[x] = y;
	s[y] += s[x];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	for (int i = 0; i < 500001; ++i) { 
		p[i] = i;
		s[i] = 1;
	}

	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int m;
		cin >> m;
		unordered_set<int> cauldron;
		int numIngredients = 0;
		for (int j = 0; j < m; ++j) {
			int t;
			cin >> t;
			int parent = find_set(t);
			if (cauldron.find(parent) == cauldron.end()) {
				numIngredients += s[parent];
				cauldron.insert(parent);
			}
		}
		if (numIngredients == m) {
			++ans;
			int prev = -1;
			for (auto x : cauldron) {
				if (prev != -1)
					union_set(x, prev);
				prev = x;
			}
		}
	}
	cout << ans << endl;
	return 0;
}