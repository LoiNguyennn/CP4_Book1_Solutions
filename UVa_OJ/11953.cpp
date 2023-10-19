#include <bits/stdc++.h>

using namespace std;

int n;
char a[105][105];
int dr[] = {-1, 0, 0, 1}, dc[] = {0, -1, 1, 0};

void dfs(int u, int v) {
    a[u][v] = '.';
    for (int i = 0; i < 4; ++i) {
        int x = u + dr[i], y = v + dc[i];
        if (x >= 0 && x < n && y >= 0 && y < n && a[x][y] != '.' && (a[x][y] == 'x' || a[x][y] == '@'))
            dfs(x, y);
    }
}

int main() {
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; ++tc) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] == 'x') {
                    ++ans;
                    dfs(i, j);
                }
            }
        }
        cout << "Case " << tc << ": " << ans << endl;
    }
    return 0;
}