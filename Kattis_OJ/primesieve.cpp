#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bitset<100000010> bs;
vector<int> p;

void sieve(ll upperBound) {
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= upperBound; ++i) {
		if (bs[i]) {
			for (ll j = i * i; j <= upperBound; j += i)
				bs[j] = 0;
			p.push_back(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;
	sieve(n);
	cout << p.size() << endl;
	while (q--) {
		int x;
		cin >> x;
		cout << bs[x] << endl;
	}
	return 0;
}