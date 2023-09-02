#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

#define VISITED (int)1e9

using namespace std;

int dx[] = {-1, 0, 1, 1, 0, - 1};
int dy[] = {0, 1, 1, 0, -1, -1};

int main() {
    int R, N, A, B, X;
    cin >> R >> N >> A >> B >> X;
    
    unordered_set<int> hard;
    for (int i = 0; i < X; ++i) {
        int x;
        cin >> x;
        hard.insert(x);
    }

    int label = 1;
    int m = (R << 1) - 1;
    vector<vector<int>> grid(m, vector<int>(m, -1));

    for (int i = 0; i < R; ++i)
        for (int j = 0; j <= R + i - 1; ++j) {
            grid[i][j] = label++;
            if (hard.count(grid[i][j])) 
                grid[i][j] = -1;
        }

    for (int i = 0; i < R - 1; ++i)
        for (int j = i + 1; j < m; ++j) {
            grid[R + i][j] = label++;
            if (hard.count(grid[R + i][j]))
                grid[R + i][j] = -1;
        }

    int x_a, x_b, y_a, y_b;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == A) {
                x_a = i;
                y_a = j;
            } else if (grid[i][j] == B) {
                x_b = i;
                y_b = j;
            }
        }
    }

    queue<pair<int, int>> q;
    vector<int> dist(label, -1);
    dist[grid[x_a][y_a]] = 0;
    q.emplace(x_a, y_a);
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 6; ++i) {
            int x_next = x + dx[i];
            int y_next = y + dy[i];
            if (x_next >= 0 && x_next < m && y_next >= 0 && y_next < m) {
                if (dist[grid[x_next][y_next]] != -1) continue;
                dist[grid[x_next][y_next]] = dist[grid[x][y]] + 1;
                q.emplace(x_next, y_next);
            }
        }
    }
    if (dist[grid[x_b][y_b]] > N || dist[grid[x_b][y_b]] == -1) {
        cout << "No\n";
    } else {
        cout << dist[grid[x_b][y_b]] << endl;
    }
    return 0;
}