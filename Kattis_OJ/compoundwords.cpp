#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<string> v;
    string s;
    while (cin >> s)
        v.push_back(s);
    set<string> res;
    for (int i = 0; i < v.size() - 1; ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            res.insert(v[i] + v[j]);
            res.insert(v[j] + v[i]);
        }
    }    
    for (auto x : res)
        cout << x << endl;
    return 0;
}