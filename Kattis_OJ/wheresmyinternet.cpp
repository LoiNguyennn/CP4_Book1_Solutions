#include <bits/stdc++.h>

using namespace std;

int visited[200000];

void dfs(int u, const vector<vector<int>>& AL) {
    visited[u] = true;
    for (int v : AL[u]) {
        if (!visited[v])
            dfs(v, AL);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> AL(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        AL[u - 1].push_back(v - 1);
        AL[v - 1].push_back(u - 1);
    }
    dfs(0, AL);
    int isConnected = true;
    for (int i = 0; i < n; ++i) 
        if (!visited[i]) {
            cout << i + 1 << endl;
            isConnected = false;
        }
    
    if (isConnected) {
        cout << "Connected" << endl;
    }
    return 0;
}