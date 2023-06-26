#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> visited;
stack<string> St;

void kosaraju(string u, unordered_map<string, vector<string>>& AL, int pass) {
	visited[u] = 1;
	for (int i = 1; i < AL[u].size(); ++i) 
		if (!visited[AL[u][i]])
			kosaraju(AL[u][i], AL, pass);
	if (pass == 1) {
		St.push(u);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int P, T;
	while (cin >> P >> T) {
		if (P == 0 && T == 0) break;
		cin.ignore();
		unordered_map<string, vector<string>> AL;
		unordered_map<string, vector<string>> AL_T;
		vector<string> name;

		while (!St.empty()) St.pop();
		for (auto& x : visited) x.second = 0;

		for (int i = 0; i < P; ++i) {
			string s;
			getline(cin, s);
			AL[s].push_back("");
			AL_T[s].push_back("");
			name.push_back(s);
		}

		for (int i = 0; i < T; ++i) {
			string u, v;
			getline(cin, u);
			getline(cin, v);
			AL[u].push_back(v);
			AL_T[v].push_back(u);
			visited[u] = 0;
			visited[v] = 0;
		}


		for (int i = 0; i < name.size(); ++i) 
			if (!visited[name[i]])
				kosaraju(name[i], AL, 1);
	
		for (int i = 0; i < name.size(); ++i)
			visited[name[i]] = 0;
		
		int numSCCs = 0;
		while (!St.empty()) {
			string u = St.top();
			St.pop();
			if (!visited[u]) {
				kosaraju(u, AL_T, 2);
				++numSCCs;
			}
		}
		cout << numSCCs << endl;
	}
	return 0;
}