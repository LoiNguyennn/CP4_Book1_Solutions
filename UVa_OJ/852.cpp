#include <bits/stdc++.h>

using namespace std;

bool b, w, visited[9][9];
int dr[] = {-1, 0, 0, 1}, dc[] = {0, -1, 1, 0};
int size_cc;

bool valid(int x, int y) {
	return (x >= 0 && x < 9 && y >= 0 && y < 9 && !visited[x][y]);
}

void dfs(const vector<string>& board, int r, int c) {
	visited[r][c] = true;
	++size_cc;
	for (int i = 0; i < 4; ++i) {
		int x = r + dr[i], y = c + dc[i];
		if (valid(x, y)) {
			if (board[x][y] == 'X') b = true;
			else if (board[x][y] == 'O') w = true;
			else dfs(board, x, y);
		}
	}
}

int main() {
	int TC;
	cin >> TC;
	while (TC--) {
		vector<string> board(9);
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 9; ++i)
			cin >> board[i];
		int numBlack = 0, numWhite = 0;
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == 'X') ++numBlack;
				else if (board[i][j] == 'O') ++numWhite;
			}
		}

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.' && !visited[i][j]) {
					b = false;
					w = false;
					size_cc = 0;
					dfs(board, i, j);
					if (b && w) continue;
					if (b) numBlack += size_cc;
					if (w) numWhite += size_cc; 
				}
			}
		}
		cout << "Black " << numBlack << " White " << numWhite << endl;
	}	
	return 0;
}