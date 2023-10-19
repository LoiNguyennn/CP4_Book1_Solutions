#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> dfs_num;
unordered_map<string, vector<string>> SCCs;
stack<string> Order;
string dfsRoot;
int pass;

void kosaraju(string u, unordered_map<string, vector<string>>& AL) {
    dfs_num[u] = 1;
    if (u != dfsRoot && pass == 2) SCCs[dfsRoot].push_back(u);
    for (string v : AL[u]) 
        if (dfs_num[v] == 0) 
            kosaraju(v, AL);
    if (pass == 1)
        Order.push(u);
}

int main() {
    int n, m;
    int TC_counter = 0;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        dfs_num.clear();
        SCCs.clear();
        while (!Order.empty()) Order.pop();

        if (TC_counter) cout << endl;

        unordered_map<string, vector<string>> AL;
        unordered_map<string, vector<string>> AL_T;
        unordered_set<string> name;
        for (int i = 0; i < m; ++i) {
            string u, v;
            cin >> u >> v;

            AL[u].push_back(v);
            AL_T[v].push_back(u);
            name.insert(u);
            name.insert(v);
        }

        pass = 1;
        for (string x : name) 
            if (dfs_num[x] == 0)
                kosaraju(x, AL);
        
        dfs_num.clear();
        pass = 2;

        cout << "Calling circles for data set " << ++TC_counter << ":\n";
        while (!Order.empty()) {
            if (dfs_num[Order.top()] == 0) {
                dfsRoot = Order.top();
                cout << dfsRoot;
                kosaraju(dfsRoot, AL_T);
                for (string x : SCCs[dfsRoot]) {
                    cout << ", " << x;
                }
                cout << endl;
            }
            Order.pop();
        }

    }
    return 0;
}