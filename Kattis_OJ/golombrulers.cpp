#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	while (getline(cin, s)) {
		stringstream sin(s);
		int a;
		vector<int> v;
		while (sin >> a)
			v.push_back(a);

		
		sort(v.begin(), v.end());
		unordered_set<int> s;

		bool notRuler = false;
		for (int i = 0; i < v.size() - 1; ++i) {
			for (int j = i + 1; j < v.size(); ++j) {
				if (s.find(v[j] - v[i]) != s.end())
					notRuler = true;
				s.insert(v[j] - v[i]);
			}
		}

		vector<int> missing;
		int n = v[v.size() - 1];
		for (int i = 1; i <= n; ++i) {
			if (s.find(i) == s.end()) 
				missing.push_back(i);
		}


		if (notRuler) {
			cout << "not a ruler\n";
		} else if (missing.size() > 0) {
			cout << "missing ";
			for (int i = 0; i < missing.size(); ++i) 
				cout << missing[i] << " ";
			cout << "\n";
		} else {
			cout << "perfect\n";
		}
	}
	return 0;
}