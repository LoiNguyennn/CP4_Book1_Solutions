#include <bits/stdc++.h>

using namespace std;

int damaged[20];
int serve[20];

int ans = 100; 
int n, s, r;

void backtrack(int i) {
	if (i == n + 1) {
		int cnt = 0;
		for (int j = 1; j <= n; ++j)
			if (damaged[j])
				++cnt;
		ans = min(ans, cnt);
		return;
	}

	if (serve[i]) {
		if (i - 1 >= 1 && damaged[i - 1]) {
			damaged[i - 1] = 0;
			serve[i] = 0;
			backtrack(i + 1);
			damaged[i - 1] = 1;
			serve[i] = 1;
		}

		if (i + 1 <= n && damaged[i + 1]) {
			damaged[i + 1] = 0;
			serve[i] = 0;
			backtrack(i + 1);
			damaged[i + 1] = 1;
			serve[i] = 1;
		}

		backtrack(i + 1);
	} else {
		backtrack(i + 1);
	}
}

int main() {
	cin >> n >> s >> r;
	for (int i = 0; i < s; ++i) {
		int t;
		cin >> t;
		damaged[t] = 1;
	}

	for (int i = 0; i < r; ++i) {
		int t;
		cin >> t;
		if (damaged[t]) 
			damaged[t] = 0;
		else 
			serve[t] = 1;
	}

	backtrack(1);

	cout << ans << endl;
	return 0;
}