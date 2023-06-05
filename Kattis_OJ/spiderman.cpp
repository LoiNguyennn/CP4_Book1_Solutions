#include <bits/stdc++.h>

using namespace std;

int n, inf = 1e9;
int a[105], memo[41][1001];
vector<char> res;

int climb(int id, int h) {
	if (h < 0 || (id == n && h != 0)) 
		return inf; 
	if (id == n && h == 0)
		return 0;
	int& ans = memo[id][h];
	if (ans != -1) return ans;
	ans = min(climb(id + 1, h + a[id]), climb(id + 1, h - a[id]));
	ans = max(ans , h);
	return ans;
}

void select_dp(int id, int h) {
	if (id == n || h < 0) return;
	if (climb(id + 1, h + a[id]) == memo[id][h]) {
		res.push_back('U');
		select_dp(id + 1, h + a[id]);
	} else {
		res.push_back('D');
		select_dp(id + 1, h - a[id]);
	}
}

int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		memset(memo, -1, sizeof(memo));
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		if (climb(0, 0) == inf) {
			cout << "IMPOSSIBLE\n";
		} else {
			select_dp(0, 0);
			for (int i = 0; i < res.size(); ++i)
				cout << res[i];
			cout << endl;
			res.clear();
		}
	}
	return 0;
}