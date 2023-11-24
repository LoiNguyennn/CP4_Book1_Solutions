#include <bits/stdc++.h>

using namespace std;

string s;
int memo[1001][1001];


bool isPalind(int i, int j) {
    if (i == j) return true;
    if (j - i == 1) return s[i] == s[j];

    int& ans = memo[i][j];
    if (ans != -1) return ans;

    ans = 0;
    if (s[i] == s[j]) return ans = isPalind(i + 1, j - 1);
    return ans;
}

int main() {
    while (cin >> s) {
        int n = s.size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                memo[i][j] = -1;


        set<string> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPalind(i, j)) {
                    ans.insert(s.substr(i, j - i + 1));
                }
            }
        }

        for (string x : ans) cout << x << endl;
        cout << endl;
    }
    return 0;
}