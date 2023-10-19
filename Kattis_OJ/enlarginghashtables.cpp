#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bitset<10000010> bs;
vector<ll> p;
const int sieve_size = 1e7 + 10;

void Sieve() {
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i < sieve_size; ++i) {
		if (bs[i]) {
			for (ll j = i * i; j < sieve_size; j += i)
				bs[j] = 0;	
			p.push_back(i);
		}
	}
}

bool IsPrime(ll n) {
	if (n < sieve_size) return bs[n];
	for (ll i = 0; i < (ll)p.size() && p[i] * p[i] <= n; ++i) {
		if (n % p[i] == 0) 
			return false;
	} 
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n;
	Sieve();
	while (cin >> n && n) {
		for (ll i = (n << 1) + 1; ; ++i) {
			if (IsPrime(i)) {
				if (IsPrime(n))
					cout << i << endl;
				else
					cout << i << " (" << n << " is not prime)\n";
				break;
			}
		}
	}
	return 0;
}