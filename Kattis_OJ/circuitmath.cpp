#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    bool inp[n];
    for (int i = 0; i < n; ++i) {
        char t;
        cin >> t;
        if (t == 'T') inp[i] = true;
        else inp[i] = false;
    }
    stack<bool> s;
    char c;
    while (cin >> c) {
        if (c >= 'A' && c <= 'Z') 
            s.push(inp[c - 'A']);
        else {
            if (c == '-') {
                bool tmp = s.top();
                s.pop();
                s.push(!tmp);
            }
            else {
                bool tmp1 = s.top();
                s.pop();
                bool tmp2 = s.top();
                s.pop();

                if (c == '*') s.push(tmp1 & tmp2);
                else if (c == '+') s.push(tmp1 | tmp2);
            }
        }   
    }
    if (s.top()) cout << "T\n";
    else cout << "F\n";
    return 0;
}
