#include <bits/stdc++.h>

using namespace std;

bool canOutPut(char a, char b) {
    // a is the top of stack, b is the incomming operator
    if (a == '(')
        return false;
    if (a == '*' || a == '/')
        return true;
    return (b == '+' || b == '-');
}

int main() {
    //freopen("input.txt", "r", stdin);
    int TC;
    cin >> TC;
    cin.ignore(2);
    while (TC--) {
        string s = "";
        stack<char> op;
        while (getline(cin, s) && s != "") {
            if (s[0] >= '0' && s[0] <= '9')
                cout << s;
            else if (s[0] == ')') {
                while (op.top() != '(') {
                    cout << op.top();
                    op.pop();
                }
                op.pop();
            }
            else {
                if (op.empty() || s[0] == '(')
                    op.push(s[0]);
                else {
                    while (!op.empty() && canOutPut(op.top(), s[0])) {
                        cout << op.top();
                        op.pop();
                    }
                    op.push(s[0]);
                }
            }
            s = "";
        }
        while (!op.empty()) {
            cout << op.top();
            op.pop();
        }
        cout << '\n';
        if (TC)
            cout << '\n';
    }
    return 0;
}