#include <bits/stdc++.h>

using namespace std;

int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		string s;
		int E = 0;
		vector<vector<char>> AL(26);
		while (cin >> s && s[0] != '*') {
			++E;
			char a = s[1], b = s[3];
			AL[a - 'A'].push_back(b);
			AL[b - 'A'].push_back(a);
		}
		cin >> s;
		int V = 0, acorn = 0;
		for (int i = 0; i < s.length(); i += 2) {
			++V;
			if (AL[s[i] - 'A'].size() == 0)
				++acorn;
		}
		int nCCs = V - E;
		cout << "There are " << nCCs - acorn << " tree(s) and " << acorn << " acorn(s).\n";
	}
	return 0;
}