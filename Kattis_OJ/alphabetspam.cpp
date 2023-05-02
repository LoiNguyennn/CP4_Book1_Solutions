#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000000
#define INP() freopen("input.txt", "r", stdin)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    string s;
    cin >> s;
    int upper = 0, lower = 0, whitespace = 0, symbol = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '_')
            ++whitespace;
        else if (s[i] >= 'a' && s[i] <= 'z')
            ++lower;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            ++upper;
        else 
            ++symbol;
    }
    cout << fixed << setprecision(16) << (double)whitespace / s.length() << endl;
    cout << fixed << setprecision(16) << (double)lower / s.length() << endl;    
    cout << fixed << setprecision(16) << (double)upper / s.length() << endl;
    cout << fixed << setprecision(16) << (double)symbol / s.length() << endl;
    return 0;
}