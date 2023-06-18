#include <bits/stdc++.h>

using namespace std;

int lab[100000];
int n, m;

int Kahn(int take, vector<int> indeg, vector<vector<int>>& AL) {
	queue<int> q0, q1; // lab1, lab2
	for (int i = 0; i < n; ++i) {
		if (indeg[i] == 0) {
			if (lab[i]) q1.push(i);
			else q0.push(i);
		}
	}
	int cnt = 0;
	while (!q0.empty() || !q1.empty()) {
		int u;
		if (take == 0) {
			if (q0.empty()) {
				++cnt;
				take = 1;
				continue;
			}
			u = q0.front(); 
			q0.pop();
		} else {
			if (q1.empty()) {
				take = 0;
				++cnt;
				continue;
			}
			u = q1.front();
			q1.pop();
		}

		for (int v : AL[u]) {
			--indeg[v];
			if (indeg[v] == 0) {
				if (lab[v]) q1.push(v);
				else q0.push(v);
			}
		}
	}
	return cnt;
}

int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			cin >> lab[i];
			--lab[i];
		}
		vector<vector<int>> AL(n);
		vector<int> indeg(n, 0);
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			--a; --b;
			AL[a].push_back(b);
			++indeg[b];
		}

		cout << min(Kahn(0, indeg, AL), Kahn(1, indeg, AL)) << endl;
	}
	return 0;
}