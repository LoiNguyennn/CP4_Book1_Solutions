#include <bits/stdc++.h>

using namespace std;

int h, w;
int grid[100][100], memo[100][100], dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
int num_sinks;

int dp(int i, int j) {
    if (memo[i][j] != -1) return memo[i][j];
    int lowest = grid[i][j], dir = -1;
    for (int k = 0; k < 4; ++k) {
        int x = i + dx[k], y = j + dy[k];
        if (x >= 0 && x < h && y >= 0 && y < w) {
            if (grid[x][y] < lowest) {
                lowest = grid[x][y];
                dir = k;
            }
        } 
    }
    if (dir == -1) {
        memo[i][j] = num_sinks++;
        return memo[i][j];
    }
    return memo[i][j] = dp(i + dx[dir], j + dy[dir]);
}

int main() {
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; ++tc) {
        cout << "Case #" << tc << ":\n";
        cin >> h >> w;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j) {
                cin >> grid[i][j];
                memo[i][j] = -1;
            }

        num_sinks = 0;
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                if (memo[i][j] == -1)
                    dp(i, j);

        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cout << char(memo[i][j] + 'a') << " ";
            }
            cout << endl;
        }        
    }
    return 0;
}