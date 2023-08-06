#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MOD ((1 << 31) - 1)

using namespace std;

char grid[1000][1000];
bool visited[1000][1000];
int dx[] = {0, 1, -1, 0};
int dy[] = {1, 0, 0, -1};

int n;

bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != '#';
}

void dfs(int x, int y) {
	visited[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		int x_n = x + dx[i];
		int y_n = y + dy[i];
		if (valid(x_n, y_n) && !visited[x_n][y_n]) 
			dfs(x_n, y_n);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < n; ++j) 
			grid[i][j] = s[j];
	}	

	long long cnt[n][n];
	memset(cnt, 0, sizeof(cnt));
	cnt[0][0] = 1;

	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			for (int k = 0; k < 2; ++k) {
				int x_n = x + dx[k];
				int y_n = y + dy[k];
				if (valid(x_n, y_n)) {
					cnt[x_n][y_n] += cnt[x][y];
					cnt[x_n][y_n] %= MOD;
				}
			}
		}
	}

	dfs(0, 0);

	if (cnt[n - 1][n - 1]) {
		cout << cnt[n - 1][n - 1] << endl;
	} else if (visited[n - 1][n - 1]) {
		cout << "THE GAME IS A LIE\n";
	} else {
		cout << "INCONCEIVABLE\n";
	}
	return 0;
}