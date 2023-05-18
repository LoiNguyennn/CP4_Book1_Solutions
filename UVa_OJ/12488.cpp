#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int n;
	while (cin >> n) {
		int start[n], finish[n];
		for (int i = 0; i < n; ++i) 
			cin >> start[i];
		for (int i = 0; i < n; ++i)
			cin >> finish[i];

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j) {
				if (finish[j] == start[i]) {
					ans += j - i;
					swap(finish[i], finish[j]);
					int tmp = j;
					while (tmp > i + 1) {
						swap(finish[tmp], finish[tmp - 1]);
						--tmp;
					}
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}