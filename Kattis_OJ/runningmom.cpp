#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> EXPLORED;
unordered_map<string, vector<string>> AL;
bool hasCycle;

void dfs(string u) {
    EXPLORED[u] = 1;
    for (string v : AL[u]) {
        if (EXPLORED[v] == 2) continue;
        if (EXPLORED[v] == 1) {
            hasCycle = true;
            return;
        }    
        dfs(v);
    }
    EXPLORED[u] = 2;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string o, d;
        cin >> o >> d;
        AL[o].push_back(d);
    }
    string s;
    while (cin >> s) {
        EXPLORED.clear();
        hasCycle = false;
        dfs(s);
        cout << s << " ";
        if (hasCycle) cout << "safe\n";
        else cout << "trapped\n";
    }
    return 0;
}