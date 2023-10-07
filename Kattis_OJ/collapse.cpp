#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> AL(n);
    vector<int> need(n, 0), s(n, 0);
    for (int u = 0; u < n; ++u) {
        int k;
        cin >> need[u] >> k;
        for (int i = 0; i < k; ++i) {
            int v, w;
            cin >> v >> w;
            --v;
            s[u] += w;
            AL[v].push_back({u, w});            
        }
    }
    
    queue<int> q;
    q.push(0);
    s[0] = INF;
    int collapse = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ++collapse;
        for (auto it : AL[u]) {
            int v = it.first, w = it.second;
            if (s[v] == INF) continue;
            s[v] -= w;
            if (s[v] < need[v]) {
                s[v] = INF;
                q.push(v);
            }
        }

    }
    cout << n - collapse << endl;
    return 0;
}