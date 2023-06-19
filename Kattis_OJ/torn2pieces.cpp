#include <bits/stdc++.h>

using namespace std;

unordered_map<string, unordered_set<string>> AL;
unordered_map<string, int> VISITED;
deque<string> path;
string start, dest;
bool found = false;


void dfs(string u) {
	VISITED[u] = 1;
	path.push_back(u);
	if (u == dest) {
		found = true;
		return;
	}
	for (auto v : AL[u]) {
		if (!VISITED[v]) 
			dfs(v);
		if (found) return;
	}
	path.pop_back();
}

int main() {
	int n;
	cin >> n;
	cin.ignore();
	for (int i = 0; i < n; ++i) {
		string s;
		getline(cin, s);
		stringstream sin(s);
		string root;
		sin >> root;
		while (sin >> s) {
			AL[root].insert(s);
			AL[s].insert(root);
		}
	}
	cin >> start >> dest;
	dfs(start);
	if (found) {
		while (!path.empty()) {
			cout << path.front() << " ";
			path.pop_front();
		}
		cout << endl;
	} else {
		cout << "no route found\n";
	}
	return 0;
}