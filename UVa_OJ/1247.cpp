#include <iostream>
#include <vector>

#define inf 1e9

using namespace std;

int AM[26][26], trace[26][26];

vector<char> ans;

int main() {
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < 26; ++j) {
			AM[i][j] = inf;
			if (i == j) AM[i][j] = 0;
			trace[i][j] = j;
			trace[j][i] = i;
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
					trace[i][j] = trace[i][k];
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

		cout << char(u + 'A');
		while (u != v) {
			u = trace[u][v];
			cout << " " << char(u + 'A');
		}
		cout << endl;
	}
	return 0;
}