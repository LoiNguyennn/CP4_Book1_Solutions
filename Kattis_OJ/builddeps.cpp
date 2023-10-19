#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> toint;
unordered_map<int, string> toname;
vector<vector<int>> AL(100000);
vector<int> ans;
bool visited[100000];

void dfs(int u) {
    visited[u] = true;
    for (int v : AL[u]) {
        if (!visited[v])
            dfs(v);
    }
    ans.push_back(u);
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    string str;    
    vector<vector<string>> v(n);
    
    for (int i = 0; i < n; ++i) {
        getline(cin, str);
        stringstream sin(str);
        sin >> str;
        str.pop_back();
        toint[str] = i;
        toname[i] = str;
        while (sin >> str) v[i].push_back(str);
    }    

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < v[i].size(); ++j)
            AL[toint[v[i][j]]].push_back(i);

    cin >> str;
    dfs(toint[str]);        
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << toname[ans[i]] << endl;
    }
    return 0;
}