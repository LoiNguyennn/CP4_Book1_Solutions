#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> hierholzer(int s, vector<vector<int>>& AL) {
	stack<int> st;
	vector<int> ans;
	int idx[AL.size()] = {0};
	st.push(s);
	while (!st.empty()) {
		int u = st.top();
		if (idx[u] < AL[u].size()) {
			st.push(AL[u][idx[u]]);
			++idx[u];
		} else {
			ans.push_back(u);
			st.pop();
		}
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0) break;
		vector<vector<int>> AL(n);
		int in_deg[n] = {0};
		int out_deg[n] = {0};

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			AL[u].push_back(v);
			++in_deg[v];
			++out_deg[u];
		}

		int start_node = 0;
		int extra_in = 0, extra_out = 0, in_equal_out = 0;

		for (int i = 0; i < n; ++i) {
			if (out_deg[i] - in_deg[i] == 1) {
				++extra_out;
				start_node = i;
			} else if (in_deg[i] - out_deg[i] == 1) {
				++extra_in;
			} else if (in_deg[i] == out_deg[i]) {
				++in_equal_out;
			}
		}
	
		vector<int> ans;
		if (extra_in == 1 && extra_out == 1 && in_equal_out == n - 2) {
			ans = hierholzer(start_node, AL);
		} else if (extra_in == 0 && extra_out == 0 && in_equal_out == n) {
			ans = hierholzer(start_node, AL);
		}
		if (ans.size() - 1 != m) {
			cout << "Impossible\n";
		} else {
			for (int i = 0; i < ans.size(); ++i)
				cout << ans[i] << " ";
			cout << endl;
		}
	}
	return 0;
}