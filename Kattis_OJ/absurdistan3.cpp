/*
    if i-th edge joints a and b, we can imagine that 
    the edge is a vertix with index (i + n) joints a and b. Then we will
    have a bipartite graph with s1 = {0,...,n-1} and s2 = {n,...,2n - 1}.
    Then just apply normal MCBM algorithm
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> AL;
vector<bool> visited;
vector<int> match;

int Aug(int L) {
    if (visited[L]) return 0;
    visited[L] = true;
    for (int R : AL[L]) {
        if (match[R] == - 1 || Aug(match[R])) {
            match[R] = L;
            return 1;
        }
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    
    AL.resize(n << 1);
    vector<pair<int, int>> edges;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        AL[a].push_back(i + n);
        AL[b].push_back(i + n);
        edges.push_back({a, b});
    }    

    match.assign(n << 1, -1);
    for (int i = 0; i < n; ++i) {
        visited.assign(n << 1, false);
        Aug(i);
    }

    for (int i = 0; i < edges.size(); ++i) {
        int a = edges[i].first, b = edges[i].second;
        if (match[i + n] == a) {
            cout << a + 1 << " " << b + 1 << endl;
        } else {
            cout << b + 1 << " " << a + 1 << endl;
        }
    }
    return 0;
}