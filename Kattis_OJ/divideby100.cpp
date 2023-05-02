#include <iostream>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();
    if (m > n) {
        string tmp = "0.";
        for (int i = 1; i <= m - n - 1; ++i)
            tmp += "0";
        s1 = tmp + s1;
    } else {
        s1.insert(s1.begin() + n - m + 1, '.');
    }
    while (s1.length() != 0 && s1[s1.length() - 1] == '0')
        s1.pop_back();
    if (s1.length() != 0 && s1[s1.length() - 1] == '.') s1.pop_back();
    cout << s1 << endl;
    return 0;
}