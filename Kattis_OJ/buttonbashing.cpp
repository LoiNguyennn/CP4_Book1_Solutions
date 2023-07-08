#include <bits/stdc++.h>

using namespace std;

int dist[3601];
int n, t;

void bfs(vector<int>& button) {
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int w : button) {
            int v = u + w;
            v = min(v, 3600); // prevent exceed 1hour
            v = max(v, 0); // prevent negative
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
            if (v == t) return;
        }
    }
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n >> t;
        memset(dist, -1, sizeof(dist));
        vector<int> button(n);
        for (int i = 0; i < n; ++i)
            cin >> button[i];
        bfs(button);
        for (int i = t; i <= 3600; ++i) {
            if (dist[i] != -1) {
                cout << dist[i] << " " << i - t << endl;
                break;
            }
        }

    }    
    return 0;
}