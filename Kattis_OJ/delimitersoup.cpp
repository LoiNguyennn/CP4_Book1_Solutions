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
    cin.ignore();

    string s;
    getline(cin, s);
    
    stack<char> st;
    for (int i = 0; i < n; ++i) {
        if (s[i] != ' ') {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[')
                st.push(s[i]);
            else {
                if (st.empty()) {
                    cout << s[i] << " " << i << endl;
                    return 0;
                }
                if (s[i] == '}' && st.top() != '{') {
                    cout << s[i] << " " << i << endl;
                    return 0;
                }
                if (s[i] == ']' && st.top() != '[') {
                    cout << s[i] << " " << i << endl;
                    return 0;
                }
                if (s[i] == ')' && st.top() != '(') {
                    cout << s[i] << " " << i << endl;
                    return 0;
                }
                st.pop();
            }
        }
    }
    cout << "ok so far\n";
    return 0;
}