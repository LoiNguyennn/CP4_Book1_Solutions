#include <bits/stdc++.h>

using namespace std;

int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		int a, b, c;
		cin >> a >> b >> c;
		int x;
		for (x = -100; x <= 100; ++x) {
			for (int y = -100; y <= 100; ++y) {
				for (int z = -100; z <= 100; ++z) {
					if ((y != x) && (z != x) && (z != y) && x + y + z == a && x * y * z == b && x * x + y * y + z * z == c) {
						cout << x << " " << y << " " << z << endl;
						x = y = z = 100000;
					}
				}
			}
		}
		if (x != 100001)
			cout << "No solution.\n";
	}
	return 0;
}