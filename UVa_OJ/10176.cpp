#include <bits/stdc++.h>

#define MOD 131071

using namespace std;

int main() {
    char c;
    while (cin >> c) {
        int ans = c - '0';
        while (cin >> c && c != '#') {
            ans <<= 1;
            ans += c - '0';
            ans %= MOD;
        }
        if (ans == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}