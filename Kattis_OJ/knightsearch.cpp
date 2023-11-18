#include <bits/stdc++.h>

using namespace std;

char board[101][101];
string s = "ICPCASIASG";

int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
int n;

bool valid(int x, int y) { return x >= 0 && x < n && y >= 0 && y < n; }

bool Try(int i, int j, int id) {
    if (id == s.size()) return true;
    for (int k = 0; k < 8; ++k) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (valid(x, y) && board[x][y] == s[id] && Try(x, y, id + 1))
            return true;
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'I') {
                if (Try(i, j, 1)) {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }

    cout << "NO\n";
    return 0;
}