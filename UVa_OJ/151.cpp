#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		int m = 0;
		while (++m) {
			deque<int> dq;
			for (int i = 1; i <= n; ++i)
				dq.push_back(i);
			dq.pop_front();

			while (dq.size() > 1) {
				for (int i = 1; i < m; ++i) {
					dq.push_back(dq.front());
					dq.pop_front();
				}
				if (dq.front() == 13) {
					dq.pop_front();
					break;
				}
				dq.pop_front();
			}
			if (dq.front() == 13) {
				cout << m << endl;
				break;
			}
		}
	}
	return 0;
}