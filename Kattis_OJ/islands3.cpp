#include <bits/stdc++.h>

using namespace std;

int r, c;
char a[50][50];
int dr[] = {-1, 0, 0, 1}, dc[] = {0, -1, 1, 0};
bool visited[50][50];

bool valid(int x, int y) {
    return (x >= 0 && x < r && y >= 0 && y < c && !visited[x][y] && (a[x][y] == 'L' || a[x][y] == 'C'));
}

void dfs(int u, int v) {
    a[u][v] = 'L';
    visited[u][v] = true;
    for (int i = 0; i < 4; ++i) {
        int x = u + dr[i], y = v + dc[i];
        if (valid(x, y))
            dfs(x, y);
    }
}

int main() {
    cin >> r >> c;
    cin.ignore();
    for (int i = 0; i < r; ++i) {
        string s;
        getline(cin, s);
        for (int j = 0; j < c; ++j)
            a[i][j] = s[j];
    }
    int ans = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (a[i][j] == 'L' && !visited[i][j]) {
                dfs(i, j);
                ++ans;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
