#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> used;
unordered_map<char, int> indeg;
unordered_map<char, vector<char>> AL;
vector<char> var;
string cur = "";
vector<string> res;

void backtrack() {
    if (cur.length() == var.size()) {
        res.push_back(cur);
        return;
    }
    for (int i = 0; i < var.size(); ++i) {
        if (used[var[i]] || indeg[var[i]] != 0) 
            continue;
        
        cur += var[i];
        used[var[i]] = 1;
        for (char v : AL[var[i]])
            --indeg[v];
    
        backtrack();
        
        cur.pop_back();
        used[var[i]] = 0;
        for (char v : AL[var[i]])
            ++indeg[v];
    }
}

int main() {
    int TC;
    cin >> TC;
    cin.ignore();
    string s;
    getline(cin, s);
    while (TC--) {
        getline(cin, s);
        stringstream sin(s);
        while (sin >> s) 
            var.push_back(s[0]);
        
        getline(cin, s);
        sin.clear();
        sin.str(s);

        while (sin >> s) { 
            AL[s[0]].push_back(s[2]);
            ++indeg[s[2]];
        }        

        backtrack();

        if (res.size()) {
            for (int i = 0; i < res.size(); ++i) {
                for (int j = 0; j < res[i].length(); ++j) {
                    if (j) cout << " ";
                    cout << res[i][j];
                }
                cout << endl;
            }
        }
        else
            cout << "NO\n";
        if (TC) cout << endl;
        used.clear();
        indeg.clear();
        AL.clear();
        var.clear();
        res.clear();
        cur = "";
        getline(cin, s);
    }
    return 0;
}