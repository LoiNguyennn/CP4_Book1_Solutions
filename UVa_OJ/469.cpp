#include <bits/stdc++.h>

using namespace std;

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool visited[105][105];
int ans = 0, n = 0, m = 0;

void dfs(int i, int j, vector<string>& a) {
    visited[i][j] = true;
    ++ans;
    for (int u = 0; u < 8; ++u) {
        int x = i + dr[u];
        int y = j + dc[u];
        if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 'W' && !visited[x][y]) {
            dfs(x, y, a);
        }
    }
}

int main() {
    int TC;
    cin >> TC;
    cin.ignore();

    while (TC--) {
        vector<string> a;
        string s;
        cin >> s;
        cin.ignore();
        do {
            a.push_back(s);
        } while (getline(cin, s) && (s[0] == 'L' || s[0] == 'W'));
        
        n = a.size();
        m = a[0].size(); 


        do {
            stringstream sin(s);
            int i, j;
            sin >> i >> j;
            
            ans = 0;
            memset(visited, false, sizeof(visited));
            dfs(i - 1, j - 1, a);
            cout << ans << endl;
        }    while (getline(cin, s) && s.length() != 0);
        if (TC)
            cout << endl;
    }
    return 0;
}