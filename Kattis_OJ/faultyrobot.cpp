#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> AL_unforced(1001);
vector<vector<int>> AL_forced(1001);
bool visited[1001];
unordered_set<int> ans;

void dfs(int u, int bug) {
    visited[u] = true;
    for (int v : AL_unforced[u]) {
        if (bug == 1 && !visited[v]) 
            dfs(v, 0);
    }

    for (int v : AL_forced[u]) {
        if (!visited[v]) {
            dfs(v, bug);
            if (bug == 1) 
                dfs(v, 0);
        }
    }

    if (AL_forced[u].size() == 0)
        ans.insert(u);
    visited[u] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > 0) AL_unforced[a].push_back(b);
        else AL_forced[-a].push_back(b);
    }

    dfs(1, 1);
    cout << ans.size() << endl;
    return 0;
}