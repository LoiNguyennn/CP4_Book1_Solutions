#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);
	int N;
	cin >> N;
	while (N != 0) {
		bool flag = true;
		for (int j = 1234; j <= 98765 / N; ++j) {
			int mask = 0;
			if (j < 10000) mask |= 1;
			int i = j * N;
			int tmp = i;
			while (tmp) {
				mask |= (1 << (tmp % 10));
				tmp /= 10;
			}
			tmp = j;
			while (tmp) {
				mask |= (1 << (tmp % 10));
				tmp /= 10;
			}
			if (mask == ((1 << 10) - 1)) {
				flag = false;
				if (i < 10000)
					cout << "0";
				cout << i << " / ";
				if (j < 10000)
					cout << "0";
				cout << j << " = " << N << endl;
			}
		}
		if (flag) {
			cout << "There are no solutions for " << N << ".\n";
		}
		cin >> N;
		if (N) cout << endl;
	}
	return 0;
}