#include <bits/stdc++.h>

#define LSOne(S) ((S) & (-S))

using namespace std;

typedef long long ll;

ll ft[5000001];
ll n, q;

void update(ll i, ll v) {
	for (; i <= n; i += LSOne(i)) 
		ft[i] += v;
}

ll rsq(ll i) {
	ll sum = 0;
	while (i) {
		sum += ft[i];
		i -= LSOne(i);
	}
	return sum;
}

int main() {
	scanf("%lld%lld\n", &n, &q);
	while (q--) {
		char c;
		scanf("%c", &c);
		if (c == '+') {
			ll i, v;
			scanf("%lld%lld\n", &i, &v);
			++i;
			update(i, v);
		} else {
			ll i;
			scanf("%lld\n", &i);
			printf("%lld\n", rsq(i));
		}
	}
	return 0;
}