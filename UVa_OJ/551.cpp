#include <bits/stdc++.h>

using namespace std;

bool check(string in, int& i) {
    vector<string> v;
    for (i = 0; i < in.length() - 1; ++i) {
        if (in[i] == '*' && in[i + 1] == ')') {
            v.push_back("*)");
            ++i;
        } else {
            string tmp = "";
            tmp += in[i];
            if (tmp == "(" && in[i + 1] == '*') {
                tmp += "*";
                ++i;
            }
            v.push_back(tmp);
        }
    }
    if (i == in.length() - 1) {
        string tmp = "";
        tmp += in[i];
        v.push_back(tmp);
    }  
    stack<pair<string, int>> s;
    for (i = 0; i < v.size(); ++i) {
        if (v[i] == "(" || v[i] == "[" || v[i] == "{" || v[i] == "(*")
            s.push({v[i], i});
        else if (v[i] == ")" || v[i] == "]" || v[i] == "}" || v[i] == "*)") {
            if (s.empty()) return false;
            else if (v[i] == ")" && s.top().first != "(") return false;
            else if (v[i] == "]" && s.top().first != "[") return false;
            else if (v[i] == "}" && s.top().first != "{") return false;
            else if (v[i] == "*)" && s.top().first != "(*") return false;
            s.pop();
        }
    }
    if (s.empty())
        return true;
    return false;
}

int main() {
    string in;
    while (cin >> in) {
        int i;
        if (check(in, i))
            cout << "YES\n";
        else 
            cout << "NO " << i + 1 << endl;
    }
    return 0;
}