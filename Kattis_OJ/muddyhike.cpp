#include <bits/stdc++.h>

using namespace std;

int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
bool visited[1000][1000], canReach;
int r, c, a[1000][1000];

bool valid(int u, int v, int deepest) {
    if (u < 0 || u >= r || v < 0 || v >= c) return false;
    if (visited[u][v] || a[u][v] > deepest) return false;
    return true;
}

void dfs(int u, int v, int deepest) {
    visited[u][v] = true;
    if (v == c - 1) {
        canReach = true;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int x = u + dx[i], y = v + dy[i];
        if (valid(x, y, deepest)) {
            dfs(x, y, deepest);
        }
    }
}

bool possible(int deepest) {
    memset(visited, false, sizeof(visited));
    canReach = false;
    for (int i = 0; i < r; ++i) {
        if (a[i][0] <= deepest)
            dfs(i, 0, deepest);
    }
    return canReach;
}

int main() {
    cin >> r >> c;    
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            cin >> a[i][j];

    int lo = 0, hi = 1000000;
    while (hi - lo > 1) {
        int deepest = (lo + hi) / 2;
        if (possible(deepest)) {
            hi = deepest;
        } else {
            lo = deepest + 1;
        }
    }
    if (possible(lo)) cout << lo << endl;
    else cout << hi << endl;
    return 0;
}