#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> AL;
vector<int> color;

bool bfs(int s) {
    color[s] = 0;
    queue<int> q;
    q.push(s);

    bool ok = false;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : AL[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
                ok = true;
            } else if (color[v] != color[u]) {
                ok = true;
            }
        }
    }
    return ok;
}

int main() {
    int n, m;
    cin >> n >> m;

    AL.resize(n);
    color.assign(n, -1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        AL[u].push_back(v);
        AL[v].push_back(u);
    }

    bool ok = true;
    for (int i = 0; i < n && ok; ++i) {
        if (color[i] == -1) {
            ok = bfs(i);
        }
    }

    if (!ok) {
        cout << "Impossible\n";
    } else {
        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                cout << "pub ";
            } else {
                cout << "house ";
            }
        }
        cout << endl;
    }


    return 0;
}
