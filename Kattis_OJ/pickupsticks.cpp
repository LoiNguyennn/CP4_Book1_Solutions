#include <bits/stdc++.h>

using namespace std;

void Kahn(const vector<vector<int>>& AL, vector<int>& indeg, vector<int>& res) {    
    queue<int> q;
    for (int i = 0; i < indeg.size(); ++i)
        if (indeg[i] == 0) {
            res.push_back(i);
            q.push(i);
        }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : AL[u]) {
            --indeg[v];
            if (indeg[v] == 0) {
                res.push_back(v);
                q.push(v);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> AL(n);
    vector<int> indeg(n, 0);
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        AL[a].push_back(b);
        ++indeg[b];
    }

    vector<int> res;
    Kahn(AL, indeg, res);

    if (res.size() == n) {
        for (int i = 0; i < res.size(); ++i)
            cout << res[i] + 1 << endl;
    } else {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}