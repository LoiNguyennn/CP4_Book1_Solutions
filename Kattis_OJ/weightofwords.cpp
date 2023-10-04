#include <bits/stdc++.h>

using namespace std;

int memo[41][1001];

int can(int i, int j) {
    if (i == 0 && j == 0) return 1;
    if (j == 0) return 0;
    if (i < 0 || j < 0) return 0;

    int& ans = memo[i][j];
    if (ans != -1) return ans;
    for (int k = 1; k <= 26; ++k) {
        ans = max(ans, can(i - 1, j - k));
    }
    return ans;
}

void printSol(int i, int j) {
    if (i < 0 || j < 0) return;
    for (int k = 1; k <= 26; ++k) {
        if (can(i - 1, j - k)) {
            cout << char('a' + k - 1);
            printSol(i - 1, j - k);
            break;
        }
    }
}

int main() {
    int l, w;
    cin >> l >> w;
    memset(memo, -1, sizeof(memo));
    if (can(l, w)) {
        printSol(l, w);
    } else {
        cout << "impossible\n";
    }
    return 0;
}