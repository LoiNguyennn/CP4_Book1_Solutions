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
    int n, m;
    cin >> n >> m;
    while (n && m) {
        unordered_set<int> s;
        s.reserve(n + m);
        int ans = 0;
        for (int i = 0; i < n + m; ++i) {
            int t;
            cin >> t;
            if (s.find(t) != s.end())
                ++ans;
            else 
                s.insert(t);
        }   
        cout << ans << endl;
        cin >> n >> m;
    }
    return 0;
}