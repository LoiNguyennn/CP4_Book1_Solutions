#include <bits/stdc++.h>

using namespace std;

bool possible(string u, string v) {
    if (u.length() != v.length()) return false;
    int numDiff = 0;
    for (int i = 0; i < u.length(); ++i)
        if (u[i] != v[i]) 
            ++numDiff;
    return numDiff == 1;
}

string start, dest;
unordered_map<string, int> dist;

void bfs(unordered_map<string, vector<string>>& AL) {
    queue<string> q;
    q.push(start);
    dist[start] = 1;
    while (!q.empty()) {
        string u = q.front();
        q.pop();
        for (string v : AL[u]) {
            if (dist[v] == 0) {
                dist[v] = dist[u] + 1;
                q.push(v);
                if (v == dest) return;
            }
        }
    }
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        vector<string> vertices;
        string s;
        while (cin >> s && s != "*")
            vertices.emplace_back(s);

        unordered_map<string, vector<string>> AL;
        for (int i = 0; i < vertices.size(); ++i) 
            for (int j = i + 1; j < vertices.size(); ++j) 
                if (possible(vertices[i], vertices[j])) {
                    AL[vertices[i]].emplace_back(vertices[j]);
                    AL[vertices[j]].emplace_back(vertices[i]);
                }
        
        cin.ignore();    
        while (getline(cin, s) && s != "") {
            stringstream sin(s);
            sin >> start >> dest;
            dist.clear();
            bfs(AL);
            cout << start << " " << dest << " " << dist[dest] - 1 << endl;
        }
        if (TC) cout << endl;
    }
    return 0;
}