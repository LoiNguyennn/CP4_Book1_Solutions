#include <bits/stdc++.h>

#define LSOne(S) ((S) & (-S))

using namespace std;

int factorial(int n) {
	int ans = 1;
	for (int i = 1; i <= n; ++i)
		ans *= i;
	return ans;
}

int main() {
	int R;
	cin >> R;
	string routines[R];
	for (int i = 0; i < R; ++i)
		cin >> routines[i];

	int N = factorial(R);
	int ans = INT_MAX;
	for (int p = 1; p <= N - 1; ++p) {
		int prev = 0, next = 0;
		for (int i = 0; i < routines[0].length(); ++i)
			prev |= (1 << (routines[0][i] - 'A'));
		
		int numQuick = 0;
		for (int i = 1; i < R; ++i) {
			for (int j = 0; j < routines[i].length(); ++j) 
				next |= (1 << (routines[i][j] - 'A'));
			
			int tmp = next;
			while (prev & next) { 
				if (LSOne(prev) == LSOne(next)) {
					++numQuick;
					prev -= LSOne(prev);
					next -= LSOne(next);
				} else if (LSOne(prev) > LSOne(next)) {
					next -= LSOne(next);
				} else {
					prev -= LSOne(prev);
				}
			}
			prev = tmp;
			next = 0;
		}
		ans = min(ans, numQuick);
		next_permutation(routines, routines + R);
	}
	cout << ans << endl;
	return 0;
}