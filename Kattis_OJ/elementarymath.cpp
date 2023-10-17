#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<vector<ll>> AL;
unordered_map<ll, int> visited;
unordered_map<ll, ll> match;

int Aug(ll L) {
	if (visited[L]) return 0;
	visited[L] = true;
	for (ll R : AL[L]) {
		if (match[R] == -1 || Aug(match[R])) {
			match[R] = L;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	AL.resize(n);
	vector<pair<int, int>> v;
	for (int i = 0; i < n; ++i) {
		ll a, b;
		cin >> a >> b;
		ll add = a + b, sub = a - b, mul = a * b;
		match[add] = match[sub] = match[mul] = -1;
		AL[i].push_back(add);
		AL[i].push_back(sub);
		AL[i].push_back(mul);
		v.push_back({a, b});
	}	

	int MCBM = 0;
	for (int i = 0; i < n; ++i) {
		visited.clear();
		MCBM += Aug(i);
	}

	if (MCBM != n) {
		cout << "impossible\n";
	} else {
		for (int i = 0; i < n; ++i) {
			ll a = v[i].first, b = v[i].second;
			if (match[a + b] == i) {
				cout << a << " + " << b << " = " << a + b << endl;
			} else if (match[a - b] == i) {
				cout << a << " - " << b << " = " << a - b << endl;
			} else if (match[a * b] == i) {
				cout << a << " * " << b << " = " << a * b << endl;
			}
		}
	}
	return 0;
}