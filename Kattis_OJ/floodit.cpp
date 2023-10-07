#include <bits/stdc++.h>

using namespace std;

int n, times, size_ccs;
set<int> candidates;
int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};

bool valid(int x, int y) { return (x >= 0 && x < n && y >= 0 && y < n); }

void bfs(int color, vector<vector<int>> grid, vector<vector<int>> visited) {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = ++times;
    grid[0][0] = color;
    while (!q.empty()) {
        int u = q.front().first, v = q.front().second;
        q.pop();
        ++size_ccs;
        for (int k = 0; k < 4; ++k) {
            int x = u + dx[k];
            int y = v + dy[k];
            if (valid(x, y)) {
                if (visited[x][y] == times - 1 || (visited[x][y] != times && grid[x][y] == color)) {
                    q.push({x, y});
                    visited[x][y] = times;
                    grid[x][y] = color;
                }
            }
        }
    }
}

void bfs(int color, vector<vector<int>>& grid, vector<vector<int>>& visited, int dummy) {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = ++times;
    grid[0][0] = color;
    while (!q.empty()) {
        int u = q.front().first, v = q.front().second;
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int x = u + dx[k];
            int y = v + dy[k];
            if (valid(x, y)) {
                if (visited[x][y] == times - 1 || (visited[x][y] != times && grid[x][y] == color)) {
                    q.push({x, y});
                    visited[x][y] = times;
                    grid[x][y] = color;
                } else if (visited[x][y] == -1) {
                    candidates.insert(grid[x][y]);
                }
            }
        }
    }
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, 0));
        vector<vector<int>> visited(n, vector<int>(n, -1));
        unordered_map<int, int> ans;

        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for (int j = 0; j < n; ++j)
                grid[i][j] = s[j] - '0';
        }
        if (n == 1) {
            cout << "0\n";
            for (int i = 1; i <= 6; ++i) {
                cout << 0 << " ";
            }
            continue;
        }

        times = 0;
        int cnt = 0;
        if (grid[0][1] == grid[0][0]) {
            bfs(grid[0][0], grid, visited, 0);
            ++cnt;
        }
        else candidates.insert(grid[0][1]);

        if (grid[1][0] == grid[0][0]) {
            bfs(grid[0][0], grid, visited, 0);
            ++cnt;
        }
        else candidates.insert(grid[1][0]);

        int max_ccs = 0, max_color = 0;

        while (candidates.size()) {
            for (int c : candidates) {
                size_ccs = 0;
                bfs(c, grid, visited);
                --times;
                if (size_ccs > max_ccs) {
                    max_ccs = size_ccs;
                    max_color = c;
                }
            }
            candidates.clear();
            ++ans[max_color];
            bfs(max_color, grid, visited, 0);
        }
        

        cout << times - cnt << endl;
        for (int i = 1; i <= 6; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}