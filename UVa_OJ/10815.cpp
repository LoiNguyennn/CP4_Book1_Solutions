#include <bits/stdc++.h>

using namespace std;

bool isAlphabet(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int main() {
    string in;
    set<string> s;
    while (cin >> in) {
        for (int i = 0; i < in.length(); ++i) {
            string tmp = "";
            while (i < in.length() && isAlphabet(in[i])) {
                if (in[i] >= 'A' && in[i] <= 'Z')
                    in[i] += 32;
                tmp += in[i];
                ++i;
            }
            if (tmp != "")
                s.insert(tmp);
        }
    }
    for (auto x : s)
        cout << x << endl;
    return 0;
}