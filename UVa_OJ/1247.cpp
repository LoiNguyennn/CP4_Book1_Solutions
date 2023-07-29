#include <iostream>
#include <vector>

#define inf 1e9

using namespace std;

int AM[26][26], parent[26][26];

vector<char> ans;

void printpath(int i, int j) {
	if (i != j)
		printpath(i, parent[i][j]);
	ans.push_back(char(j + 'A'));
}

int main() {
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j) {
			AM[i][j] = inf;
			if (i == j) AM[i][j] = 0;
			parent[i][j] = i;
			parent[j][i] = j;
		}

	int s, p;
	cin >> s >> p;
	for (int i = 0; i < p; ++i) {
		char c1, c2;
		int w;
		cin >> c1 >> c2 >> w;
		int u = c1 - 'A', v = c2 - 'A';
		AM[u][v] = w;
		AM[v][u] = w;
	}

	for (int k = 0; k < 26; ++k) {
		for (int i = 0; i < 26; ++i) {
			for (int j = 0; j < 26; ++j) {
				if (AM[i][j] > AM[i][k] + AM[k][j]) {
					AM[i][j] = AM[i][k] + AM[k][j];
					parent[i][j] = parent[k][j];
				}
			}
		}	
	}
	

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		char ek, em;
		cin >> ek >> em;
		int u = ek - 'A';
		int v = em - 'A';

			
		ans.clear();
		printpath(u, v);
		cout << ans[0];
		for (int i = 1; i < ans.size(); ++i)
			cout << " " << ans[i];
		cout << endl;
	}
	return 0;
}