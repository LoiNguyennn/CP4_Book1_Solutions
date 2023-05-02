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
    stack<int> st;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (st.empty()) st.push(t);
        else if ((st.top() + t) % 2 == 0) st.pop();
        else st.push(t);
    }
    cout << st.size() << endl;
    return 0;
}
