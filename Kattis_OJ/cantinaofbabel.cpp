#include <bits/stdc++.h>

using namespace std;

unordered_map<string, vector<string>> AL;
unordered_map<string, vector<string>> AL_T;
unordered_map<string, bool> visited;
unordered_map<string, unordered_set<string>> understand;
unordered_map<string, string> speak;
stack<string> st;
int size_scc = 0;

void kosaraju(string u, int pass) {
    visited[u] = true;
    ++size_scc;
    unordered_map<string, vector<string>> A = (pass == 1) ? AL : AL_T;
    for (string v : A[u]) {
        if (!visited[v]) {
            kosaraju(v, pass);
        }
    }
    st.push(u);
}



int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<string> names;
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        stringstream sin(s);
        
        string name;
        sin >> name;
        names.push_back(name);
        
        sin >> s;
        speak[name] = s;
        understand[name].insert(s);

        while (sin >> s)
            understand[name].insert(s);
    }

    for (string i : names) {
        for (string j : names) {
            if (i == j) continue;
            if (understand[j].count(speak[i])) {
                AL[i].push_back(j);
                AL_T[j].push_back(i);
            }
        }
    }

    for (string s : names) {
        if (!visited[s]) {
            kosaraju(s, 1);
        }
    }

    int max_scc = 0;
    visited.clear();
    while (!st.empty()) {
        string u = st.top();
        st.pop();
        if (visited[u]) continue;
        size_scc = 0;
        kosaraju(u, 2);
        max_scc = max(max_scc, size_scc);
    }
    cout << n - max_scc << endl;
    return 0;
}