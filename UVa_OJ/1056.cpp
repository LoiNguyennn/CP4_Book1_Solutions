#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

#define inf 1e9

using namespace std;

int main() {
	int p, r, tc = 1;
	while (cin >> p >> r) {
		if (p == 0 && r == 0) break;
		vector<pair<string, string>> EL;
		unordered_set<string> names;

		for (int i = 0; i < r; ++i) {
			string u, v;
			cin >> u >> v;
			EL.emplace_back(u, v);
			names.emplace(u);
			names.emplace(v);
		}

		int label = 0;
		unordered_map<string, int> F;
		for (auto x : names) 
			F[x] = label++;
		
		int AM[50][50];

		for (int i = 0; i < 50; ++i) {
			for (int j = 0; j < 50; ++j) {
				AM[i][j] = inf;
				if (i == j)
					AM[i][i] = 0;
			}
		}

		for (auto x : EL) {
			int u = F[x.first], v = F[x.second];
			AM[u][v] = AM[v][u] = 1;
		}

		for (int k = 0; k < p; ++k) {
			for (int i = 0; i < p; ++i) {
				for (int j = 0; j < p; ++j)
					AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
			}
		}

		int ans = 0, isDisconnect = 0;
		for (int i = 0; i < p; ++i) {
			for (int j = 0; j < p; ++j) {
				if (AM[i][j] != inf)
					ans = max(ans, AM[i][j]);
				else isDisconnect = 1;
			}
		}

		cout << "Network " << tc++ << ": ";
		if (isDisconnect)
			cout << "DISCONNECTED\n";
		else
			cout << ans << endl;
		cout << endl;
	}
	return 0;
}