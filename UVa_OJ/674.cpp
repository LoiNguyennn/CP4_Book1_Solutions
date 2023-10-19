#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll coin[5] = {50, 25, 10, 5, 1};
ll memo[5][7490];

ll dp(ll id, ll remV) {
    if (remV == 0)
        return 1;
    if (id == 5 || remV < 0)
        return 0;
    ll& ans = memo[id][remV];
    if (ans) return ans;
    return ans = dp(id + 1, remV) + dp(id, remV - coin[id]);
}

int main() {
    for (int i = 0; i < 7490; ++i)
        dp(0, i);
    int v;
    while (cin >> v)
        cout << memo[0][v] << endl;
    
    return 0;
}