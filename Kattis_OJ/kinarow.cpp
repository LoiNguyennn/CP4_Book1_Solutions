#include <bits/stdc++.h>

using namespace std;

int m, n, k;
char board[201][201];
bool visited[201][201];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool valid(int x, int y) {return x >= 0 && x < m && y >= 0 && y < n;}

bool dfs(int i, int j, int d, char c, int dir) {
    if (d == k) return true;
    int x = i + dx[dir];
    int y = j + dy[dir];
    if (valid(x, y) && c == board[x][y]) 
        return dfs(x, y, d + 1, c, dir);
    return false;
}

int main() {
    int g;
    cin >> g;
    int hansel = 0, gretel = 0;
    while (g--) {
        cin >> n >> m >> k;
        for (int i = 0; i < m; ++i) 
            for (int j = 0; j < n; ++j) {
                cin >> board[i][j];
            }
        
        bool end = false;
        for (int i = 0; i < m && !end; ++i) {
            for (int j = 0; j < n && !end; ++j) {
                if (board[i][j] == 'x') {
                    for (int dir = 0; dir < 8 && !end; ++dir) {
                        if (dfs(i, j, 1, 'x', dir)) {
                            ++hansel;
                            end = true;
                        }
                    }
                } else if (board[i][j] == 'o') {
                    for (int dir = 0; dir < 8 && !end; ++dir) {
                        if (dfs(i, j, 1, 'o', dir)) {
                            ++gretel;
                            end = true;
                        }
                    }
                }
            }
        }
    }   
    cout << hansel << ":" << gretel << endl;
    return 0;
}