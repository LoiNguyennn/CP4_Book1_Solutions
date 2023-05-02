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
    
    int n, k;
    cin >> n >> k;
    stack<int> st;
    st.push(0);
    for (int i = 0; i < k; ++i) {
        string s;
        cin >> s;
        if (s != "undo") {
            int a = atoi(s.c_str());
            while (a < 0) a += n;
            st.push((st.top() + a % n) % n);
        } else {
            int t;
            cin >> t;
            while (t--) st.pop();
        }
    }
    cout << st.top() << endl;
    return 0;
}
