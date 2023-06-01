#include <bits/stdc++.h>

#define INF 1e9 + 7

using namespace std;

int memo[2000][2017];

int dp(int id, int remD, vector<pair<int, int>>& state) {
	if (remD <= 0)
		return 0;
	if (id == state.size())
		return INF;
	int& ans = memo[id][remD];
	if (ans != -1)
		return ans;
	return ans = min(dp(id + 1, remD - state[id].first, state) + state[id].second, dp(id + 1, remD, state));
}

int main() {
	int S;
	cin >> S;
	vector<pair<int, int>> state;
	state.reserve(S);
	memset(memo, -1, sizeof(memo));
	int total_delegates = 0;
	while (S--) {
		int d, c, f, u;
		cin >> d >> c >> f >> u;
		total_delegates += d;

		int p = (c + f + u) / 2 + 1;
		int min_voter;

		if (c >= p) min_voter = 0;
		else if (f >= p) min_voter = -1;
		else {
			min_voter = p - c;
			if (min_voter > u) min_voter = -1;
		}
		if (min_voter != -1)
			state.push_back({d, min_voter});
	}

	int need = total_delegates / 2 + 1;

	int res = dp(0, need, state);
	if (res == INF) {
		cout << "impossible\n";
	} else {
		cout << res << endl;
	}
	return 0;
}