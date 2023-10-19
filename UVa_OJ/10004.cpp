#include <bits/stdc++.h>

using namespace std;

void bfs(const vector<vector<int>>& AL) {
    int n = AL.size();
    queue<int> q;
    q.push(0);
    int colored[n];
    colored[0] = 0;
    memset(colored, -1, sizeof(colored));

    bool isBipartite = true;
    while (!q.empty() && isBipartite) {
        int u = q.front();
        q.pop();
        for (int v : AL[u]) {
            if (colored[v] == -1) {
                colored[v] = 1 - colored[u];
                q.push(v);
            } else if (colored[u] == colored[v]) {
                isBipartite = false;
                break;
            }
        }
    }

    if (isBipartite) {
        cout << "BICOLORABLE.\n";
    } else {
        cout << "NOT BICOLORABLE.\n";
    }
}

int main() {
    int n;
    while (cin >> n && n) {
        int l;
        cin >> l;
        vector<vector<int>> AL(n);
        while (l--) {
            int u, v;
            cin >> u >> v;
            AL[u].push_back(v);
            AL[v].push_back(u);
        }
        bfs(AL);
    }
    return 0;
}