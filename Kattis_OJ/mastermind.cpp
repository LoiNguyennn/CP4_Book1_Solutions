#include <iostream>

using namespace std;

int code[26] = {0};
int guess[26] = {0};

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    string s1, s2;
    cin >> n;
    cin >> s1 >> s2;
    int r = 0, s = 0;
    for (int i = 0; i < n; ++i) {
        ++code[s1[i] - 'A'];
        ++guess[s2[i] - 'A'];
    }
    for (int i = 0; i < n; ++i)
        if (s1[i] == s2[i]) {
            ++r;
            --code[s1[i] - 'A'];
            --guess[s1[i] - 'A'];
        }
    for (int i = 0; i < 26; ++i)
        s += min(code[i], guess[i]);
    cout << r << " " << s << endl;
    return 0;
}