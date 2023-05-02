#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    int n;
    cin >> n;
    stack<int> s1, s2;
    for (int i = 1; i <= (n << 1); ++i) {
        int t;
        cin >> t;
        s1.push(t);
    }
    int ans = 0;
    while (!s1.empty()) {
        ++ans;
        if (s2.empty()) {
            s2.push(s1.top());
            s1.pop();
        } else {
            if (s1.top() == s2.top()) {
                s1.pop();
                s2.pop();
            } else {
                s2.push(s1.top());
                s1.pop();
            }
        }
    }
    if (!s1.empty() || !s2.empty()) 
        cout << "impossible\n";
    else 
        cout << ans << endl;
    return 0;
}
