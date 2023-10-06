#include <bits/stdc++.h>

using namespace std;

vector<bool> visited;

void dfs(int u, vector<vector<int>>& AL) {
    visited[u] = true;
    for (int v : AL[u]) {
        if (!visited[v]) {
            dfs(v, AL);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> AL(1001), AL_T(1001);
    vector<int> order;
    int u, k, v;
    for (int i = 0; i < n; ++i) {
        cin >> u;
        order.push_back(u);
        cin >> k;
        for (int j = 0; j < k; ++j) {
            cin >> v;
            AL[u].push_back(v);
            AL_T[v].push_back(u);
        }
    }

    bool hasProblems = false;
    visited.assign(1001, false);
    dfs(0, AL_T);
    for (int x : order) {
        if (!visited[x]) {
            hasProblems = true;
            cout << "TRAPPED " << x << endl;
        }
    }

    visited.assign(1001, false);
    dfs(0, AL);
    for (int x : order) {
        if (!visited[x]) {
            hasProblems = true;
            cout << "UNREACHABLE " << x << endl;
        }
    }

    if (!hasProblems) {
        cout << "NO PROBLEMS\n";
    }
    return 0;
}