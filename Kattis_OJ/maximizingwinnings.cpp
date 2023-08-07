#include <iostream>
#include <climits>
#include <cstring>

using namespace std;

int grid[50][50], memo[50][5001];
int n, m;

int dp(int room, int turn_left, bool req) {
	if (turn_left == 0)
		return 0;
	
	int& ans = memo[room][turn_left];
	if (ans != -1) return ans;

	if (req) {
		ans = 0;
		for (int i = 0; i < n; ++i)
			ans = max(ans, dp(i, turn_left - 1, req) + grid[room][i]);
	} else {
		ans = INT_MAX;
		for (int i = 0; i < n; ++i)
			ans = min(ans, dp(i, turn_left - 1, req) + grid[room][i]);
	}

	return ans;
}

int main() {
	while (cin >> n && n) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> grid[i][j];

		cin >> m;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j <= m; ++j)
				memo[i][j] = -1;

		cout << dp(0, m, 1) << " ";
		
		for (int i = 0; i < n; ++i)
			for (int j = 0; j <= m; ++j)
				memo[i][j] = -1;

		cout << dp(0, m, 0) << endl;
	}
	return 0;
}