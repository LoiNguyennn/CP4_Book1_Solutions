#include <bits/stdc++.h>

using namespace std;

void bicolor(int s, vector<vector<int>>& AL, vector<int>& colored) {
    queue<int> q;
    q.push(s);
    colored[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : AL[u]) {
            if (colored[v] == -1) {
                colored[v] = 1 - colored[u];
                q.push(v);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> EL(n - 1);
    vector<vector<int>> AL(n);
    vector<int> colored(n, -1);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        AL[a].push_back(b);
        AL[b].push_back(a);
        EL[i] = make_pair(a, b);
    }

    bicolor(0, AL, colored);
    for (int i = 0; i < n - 1; ++i) 
        cout << colored[EL[i].first] << endl;
    return 0;
}