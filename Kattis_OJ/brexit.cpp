#include <bits/stdc++.h>

using namespace std;

int C, P, X, L;
bool leave[200001];

void dfs(int u, vector<pair<vector<int>, int>>& AL) {
    leave[u] = true;
    for (int& v : AL[u].first) {
        ++AL[v].second;
        if (!leave[v] && (AL[v].second << 1) >= AL[v].first.size())
            dfs(v, AL);
    }
}

int main() {
    cin >> C >> P >> X >> L;
    vector<pair<vector<int>, int>> AL(C + 1);
    for (int i = 0; i < P; ++i) {
        int a, b;
        cin >> a >> b;
        AL[a].first.push_back(b);
        AL[b].first.push_back(a);
        AL[a].second = 0;
        AL[b].second = 0;
    }
    dfs(L, AL);
    if (leave[X]) cout << "leave\n";
    else cout << "stay\n";
    return 0;
}