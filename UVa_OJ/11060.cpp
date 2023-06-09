#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	int N;
	int test_case = 1;
	while (cin >> N) {
		cout << "Case #" << test_case++ << ": Dilbert should drink beverages in this order:";
		unordered_map<int, string> name;
		unordered_map<string, int> id;
		for (int i = 0; i < N; ++i) {
			string s;
			cin >> s;
			name[i] = s;
			id[s] = i;
		}

		int M;
		cin >> M;
		vector<vector<int>> AL(N);
		int in_degree[N];
		memset(in_degree, 0, sizeof(in_degree));

		for (int i = 0; i < M; ++i) {
			string b1, b2;
			cin >> b1 >> b2;
			AL[id[b1]].push_back(id[b2]);
			++in_degree[id[b2]];
		}


		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < N; ++i)
			if (in_degree[i] == 0)
				pq.push(i);

		while (!pq.empty()) {
			int u = pq.top();
			pq.pop();
			cout << " " << name[u];
			for (int v: AL[u]) {
				--in_degree[v];
				if (in_degree[v] == 0)
					pq.push(v);
			}
		}
		cout << ".\n\n";
	}
	return 0;
}