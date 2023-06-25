#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;

bool visited[2000];
stack<int> Order;

void kosaraju(int u, vector<vi>& AL) {
	visited[u] = true;
	for (int v : AL[u]) {
		if (!visited[v])
			kosaraju(v, AL);
	}
	Order.push(u);
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		memset(visited, false, sizeof(visited));
		while (!Order.empty()) Order.pop();

		vector<vi> AL(n);
		vector<vi> AL_T(n);
		int a, b, p;
		for (int i = 0; i < m; ++i) {
			cin >> a >> b >> p;
			--a; --b;
			AL[a].push_back(b);
			AL_T[b].push_back(a);
			if (p == 2) { 
				AL[b].push_back(a);
				AL_T[a].push_back(b);
			}
		}

		for (int i = 0; i < n; ++i) 
			if (!visited[i])
				kosaraju(i, AL);

		memset(visited, false, sizeof(visited));
		int ans = 0;
		while (!Order.empty()) {
			if (!visited[Order.top()]) {
				kosaraju(Order.top(), AL_T);
				++ans;
			}
			Order.pop();
		}
		if (ans == 1) {
			cout << "1\n";
		} else {
			cout << "0\n";
		}
	}
	return 0;
}