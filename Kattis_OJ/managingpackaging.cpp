#include <bits/stdc++.h>

using namespace std;

int n, hasCycle;
unordered_map<string, int> visited;
unordered_map<string, vector<string>> AL;
unordered_map<string, int> indeg;

void dfs(string u) {
    visited[u] = 1; // explored;
    for (string v : AL[u]) {
        if (visited[v] == 0) {
            dfs(v);
        } else if (visited[v] == 1) {
            hasCycle = 1;
        }
    }
    visited[u] = 2; // visited;
}

void kahn() {
    priority_queue<string, vector<string>, greater<string>> pq;
    for (auto it : indeg) {
        if (it.second == 0) 
            pq.push(it.first);
    }

    while (!pq.empty()) {
        string u = pq.top();
        pq.pop();
        cout << u << endl;
        for (string v : AL[u]) {
            --indeg[v];
            if (indeg[v] == 0)
                pq.push(v);
        }
    }
}

int main() {
    int n;
    while (cin >> n && n) {
        cin.ignore();
        AL.clear();
        visited.clear();
        indeg.clear();
        hasCycle = false;

        for (int i = 0; i < n; ++i) {
            string s;
            getline(cin, s);
            stringstream sin(s);
            
            string u;
            sin >> u;
            indeg[u] = 0;
            string v;
            while (sin >> v) {
                AL[v].push_back(u);
                ++indeg[u];
            }
        }
        for (auto x : AL) {
            if (visited[x.first] == 0)
                dfs(x.first);
        }

        if (hasCycle) {
            cout << "cannot be ordered\n";
        } else {
            kahn();
        }
        cout << endl;
    }
    return 0;
}