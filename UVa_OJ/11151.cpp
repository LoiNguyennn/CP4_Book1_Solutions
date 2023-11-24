#include <bits/stdc++.h>

using namespace std;

string s;
int memo[1001][1001];

int dp(int i, int j) {
    if (i == j) return 1;
    if (j - i == 1) return ((s[i] == s[j]) ? 2 : 1);
    int& ans = memo[i][j];
    if (ans) return ans;
    if (s[i] == s[j]) return ans = 2 + dp(i + 1, j - 1);
    return ans = max(dp(i + 1, j), dp(i, j - 1));
}

int main() {
    int TC;
    cin >> TC;
    cin.ignore();
    while (TC--) {
        memset(memo, 0, sizeof(memo));
        getline(cin, s);
        if (s.size() == 0) {
            cout << 0 << endl;
        } else {
            cout << dp(0, s.size() - 1) << endl;
        }
    }   
    return 0;
}