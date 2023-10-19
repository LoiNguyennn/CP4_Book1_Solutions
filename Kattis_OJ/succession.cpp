#include <bits/stdc++.h>

#define MAX 1000000000000

using namespace std;

typedef long double ld;

unordered_map<string, ld> royal_blood;
unordered_map<string, vector<string>> AL;
unordered_map<string, int> indeg;

void kahn() {
    queue<string> q;
    for (auto x : indeg)
        if (x.second == 0)
            q.push(x.first);

    while (!q.empty()) {
        string u = q.front();
        q.pop();
        for (string v : AL[u]) {
            royal_blood[v] += royal_blood[u] / 2;
            --indeg[v];
            if (indeg[v] == 0)
                q.push(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    string founder;
    cin >> founder;
    for (int i = 0; i < n; ++i) {
        string c, p1, p2;
        cin >> c >> p1 >> p2;
        royal_blood[p1] = 0;
        royal_blood[p2] = 0;
        royal_blood[c] = 0;
        AL[p1].push_back(c);
        AL[p2].push_back(c);
        indeg[p1] += 0;
        indeg[p2] += 0;
        indeg[c] += 2;
    }

    royal_blood[founder] = MAX;
    kahn();

    ld mx = 0;
    string ans;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        if (royal_blood[s] > mx) {
            mx = royal_blood[s];
            ans = s;
        }
    }
    cout << ans << endl;
    return 0;
}