#include <bits/stdc++.h>

using namespace std;

int r, c, s, cnt, k, l;
int EXPLORED[10][10];
bool hasCycle;

void dfs(int u, int v, vector<string>& grid) {
    EXPLORED[u][v] = 1;
    ++cnt;
    int x, y;
    if (grid[u][v] == 'N') {
        x = u - 1;
        y = v;
    } else if (grid[u][v] == 'S') {
        x = u + 1;
        y = v;
    } else if (grid[u][v] == 'W') {
        x = u;
        y = v - 1;
    } else {
        x = u;
        y = v + 1;
    }

    if (x < 0 || x >= r || y < 0 || y >= c) return;
    if (EXPLORED[x][y] == 1) {
        k = x;
        l = y;
        hasCycle = true;
    }
    else dfs(x, y, grid);
}

int main() {
    while (cin >> r >> c >> s) {
        if (r == 0 && c == 0 && s == 0)
            break;
        vector<string> grid(r);
        for (int i = 0; i < r; ++i)
            cin >> grid[i];
        --s;

        hasCycle = false;
        cnt = 0;
        memset(EXPLORED, 0, sizeof(EXPLORED));
        dfs(0, s, grid);
        if (hasCycle) 
            cout << k + abs(l - s) << " step(s) before a loop of " << cnt - (k + abs(l - s)) << " step(s)\n";
        else
            cout << cnt << " step(s) to exit" << endl;
    }
    return 0;
}