#include <bits/stdc++.h>

using namespace std;

int main() {
    string ex;
    cin >> ex;
    
    stack<int > st;
    vector<pair<int, int>> v;
    for (int i = 0; i < ex.length(); ++i) {
        if (ex[i] == '(')
            st.push(i);
        else if (ex[i] == ')') { 
            v.push_back({st.top(), i});
            st.pop();
        }
    }

    set<string> ans;
    int n = v.size();
    for (int mask = (1 << n) - 2; mask >= 0; --mask) {
        unordered_set<int> print;
        for (int i = 0; i < n; ++i)
            if (mask & (1 << i)) {
                print.insert(v[i].first);
                print.insert(v[i].second);
            }

        string tmp;
        for (int i = 0; i < ex.length(); ++i) {
            if (ex[i] != '(' && ex[i] != ')')
                tmp += ex[i];
            else if (print.find(i) != print.end())
                tmp += ex[i];
        }
        ans.insert(tmp);
    }
    for (auto x : ans)
        cout << x << endl;
    return 0;
}