#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

#define VISITED (int)1e9

using namespace std;

int dx[] = {-1, 0, 1, 1, 0, - 1};
int dy[] = {0, 1, 1, 0, -1, -1};

int main() {
    int R, K;
    cin >> R >> K;
    int label = 1;
    int N = (R << 1) - 1;
    vector<vector<int>> grid(N + 2, vector<int>(N + 2, -1));

    for (int i = 1; i <= R; ++i)
        for (int j = 1; j <= R + i - 1; ++j) 
            grid[i][j] = label++;

    for (int i = 1; i <= R - 1; ++i)
        for (int j = i + 1; j <= N; ++j)
            grid[R + i][j] = label++;

    unordered_set<int> s;
    for (int i = 0; i < K; ++i) {
        int id;
        cin >> id;
        s.insert(id);
    }
    
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    q.emplace(0, N + 1);
    q.emplace(N + 1, 0);
    q.emplace(N + 1, N + 1);
    grid[0][0] = VISITED;
    grid[0][N + 1] = VISITED;
    grid[N + 1][0] = VISITED;
    grid[N + 1][N + 1] = VISITED;

    int ans = 0;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 6; ++i) {
            int u = x + dx[i];
            int v = y + dy[i];
            if (u >= 0 && u <= N + 1 && v >= 0 && v <= N + 1) {
                if (s.count(grid[u][v]))
                    ++ans;
                else if (grid[u][v] != VISITED) {
                    grid[u][v] = VISITED;
                    q.emplace(u, v);
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}