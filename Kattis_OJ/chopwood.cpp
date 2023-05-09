#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	priority_queue<int, vector<int>, greater<int>> pq;
	
	int n;
	cin >> n;
	
	int a[n];
	unordered_map<int, int> deg;

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		++deg[a[i]];
	}
	for (int i = 1; i <= n; ++i) {
		++deg[i];
		if (deg[i] == 1)
			pq.push(i);
	}
	
	vector<int> ans;
	bool flag = false;
	for (int i = 0; i < n; ++i) {
		if (pq.empty()) {
			flag = true;
			break;
		}
		ans.push_back(pq.top());
		--deg[pq.top()];
		--deg[a[i]];
		pq.pop();
		if (deg[a[i]] == 1) {
			pq.push(a[i]);
		}
	}
	for (auto x : deg) {
		if (x.second != 0)
			flag = true;
	}
	
	if (flag) {
		cout << "Error\n";
	} else {
		for (int i = 0; i < ans.size(); ++i)
			cout << ans[i] << endl;
	}
	return 0;
}