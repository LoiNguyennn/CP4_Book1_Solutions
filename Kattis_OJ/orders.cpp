#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, p[100], memo[100][30001];
vector<ll> res;

ll dp(ll id, ll remV) {
	if (remV == 0)
		return 1;
	if (id == n || remV < 0)
		return 0;
	ll& ans = memo[id][remV];
	if (ans != -1) return ans;
	return ans = dp(id, remV - p[id]) + dp(id + 1, remV);
}

void select_dp(ll id, ll remV, vector<ll>& res) {
	if (remV == 0 || id == n)
		return;
	if (remV >= p[id] && memo[0][remV - p[id]] > 0) {
		res.push_back(id);
		select_dp(id, remV - p[id], res);
	} 
	else {
		select_dp(id + 1, remV, res);
	}
}

int main() {
	memset(memo, -1, sizeof(memo));
	memo[0][0] = 1; // it's anti-dp but we need it to insert the last coins!!!
	cin >> n;
	ll max_val = 0;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
	}

	for (int i = 0; i < 30001; ++i)
		dp(0, i);

	int m;
	cin >> m;
	while (m--) {
		ll v;
		cin >> v;
		
		if (memo[0][v] >= 2) {
			cout << "Ambiguous\n";
		} else if (memo[0][v] == 1) {
			vector<ll> res;
			select_dp(0, v, res);
			for (int i = 0; i < res.size(); ++i)
				cout << res[i] + 1 << " ";
			cout << endl;
		} else {
			cout << "Impossible\n";
		}
	}
	return 0;
}