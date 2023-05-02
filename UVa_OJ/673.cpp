#include <bits/stdc++.h>

using namespace std;

bool check(string in) {
    stack<char> s;
    for (int i = 0; i < in.length(); ++i) {
        if (in[i] == '[' || in[i] == '(')
            s.push(in[i]);
        else if (in[i] != ' ') {
            if (s.empty()) return false;
            else if (in[i] == ']' && s.top() != '[') return false;
            else if (in[i] == ')' && s.top() != '(') return false;
            s.pop();
        }
    }
    if (!s.empty())
        return false;
    return true;
}

int main() {
    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        string in;
        getline(cin, in);
        if (check(in)) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}