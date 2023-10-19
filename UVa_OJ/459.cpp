#include <bits/stdc++.h>

#define hash(x) (x - 'A')

using namespace std;

bool visited[30];
void dfs(int u, vector<vector<int>>& AL) {
    visited[u] = true;
    for (int v : AL[u]) 
        if (!visited[v])
            dfs(v, AL);
}

int main() {
    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        memset(visited, false, sizeof(visited));
        
        char c;
        cin >> c;
        cin.ignore();
        int n = hash(c) + 1;
        vector<vector<int>> AL(n);

        string s;
        while (getline(cin, s) && s.length() != 0) {
            AL[hash(s[0])].push_back(hash(s[1]));
            AL[hash(s[1])].push_back(hash(s[0]));
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++ans;
                dfs(i, AL);
            }
        }
        cout << ans << endl;
        if (TC)
            cout << endl;
    }
    return 0;
}