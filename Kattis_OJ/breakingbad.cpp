#include <bits/stdc++.h>

using namespace std;

unordered_map<string, vector<string>> AL;
unordered_map<string, int> color;
bool isBipartite = false;

void bfs(string s) {
    color[s] = 0;
    queue<string> q;
    q.push(s);
    while (!q.empty()) {
        string u = q.front();
        q.pop();
        for (string v : AL[u]) {
            if (color[v] == -1) {
                color[v] = 1 - color[u];
                q.push(v);
            } else if (color[v] == color[u]) {
                isBipartite = false;
                return;
            }
        }
    }
    isBipartite = true;
}

int main() {
    int n;
    cin >> n;
    vector<string> names(n);
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
        color[names[i]] = -1;
    }

    int m;
    cin >> m;
    if (m == 0) {
        for (string s : names) cout << s << " ";
        cout << endl;
        return 0;
    }
    unordered_set<string> se;
    for (int i = 0; i < m; ++i) {
        string a, b;
        cin >> a >> b;
        AL[a].push_back(b);
        AL[b].push_back(a);
        se.insert(a);
        se.insert(b);
    }

    for (string s : se) {
        if (color[s] == -1)
            bfs(s);
        if (!isBipartite) break;
    }


    if (!isBipartite) {
        cout << "impossible\n";
    } else {
        vector<string> w, j;
        for (string s : names) {
            if (color[s] == -1 || color[s] == 0)
                w.push_back(s);
            else
                j.push_back(s);
        }

        for (string s : w) cout << s << " ";
        cout << endl;
        for (string s : j) cout << s << " ";
        cout << endl;
    }

    return 0;
}
