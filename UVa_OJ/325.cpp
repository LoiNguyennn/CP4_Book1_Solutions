#include <bits/stdc++.h>

using namespace std;

int main() {
    regex reg("[-+]?\\d+(\\.\\d+([eE][-+]?\\d+)?|[eE][-+]?\\d+)");
    string s;
    while (getline(cin, s)) {
        stringstream sin(s);
        sin >> s;
        if (s == "*") break;
        if (regex_match(s, reg)) {
            cout << s << " is legal.\n";
        } else {
            cout << s << " is illegal.\n";
        }
    }   
    return 0;
}