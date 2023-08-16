#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<vector<int>> AL;
vector<bool> visited;
vector<int> match;

bool augumenting_path(int L) {
	if (visited[L]) return false;
	visited[L] = true;
	for (int R : AL[L]) {
		if (match[R] == -1 || augumenting_path(match[R])) {
			match[R] = L;
			return true;
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	AL.assign(n, vector<int>());
	match.assign(n, -1);

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		AL[u].push_back(v);
	}

	int MCBM = 0;
	for (int i = 0; i < n; ++i) {
		visited.assign(n, false);
		MCBM += augumenting_path(i);
	}

	if (MCBM == n) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}