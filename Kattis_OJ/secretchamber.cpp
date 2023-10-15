#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m, n;
	cin >> m >> n;
	bool AM[26][26];
	memset(AM, false, sizeof(AM));


	for (int i = 0; i < m; ++i) {
		char u, v;
		cin >> u >> v;
		AM[u - 'a'][v - 'a'] = true;
	}	

	for (int k = 0; k < 26; ++k)
		for (int i = 0; i < 26; ++i)
			for (int j = 0; j < 26; ++j)
				AM[i][j] |= (AM[i][k] & AM[k][j]);

	for (int i = 0; i < n; ++i) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1.length() != s2.length()) {
			cout << "no\n";
			continue;
		}
		bool ok = true;
		for (int i = 0; i < s1.length(); ++i) {
			if (s1[i] == s2[i]) continue;
			if (!AM[s1[i] - 'a'][s2[i] - 'a']) {
				ok = false;
				break;
			}
		}
		if (ok) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}