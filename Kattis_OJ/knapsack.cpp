#include <bits/stdc++.h>

using namespace std;

int w[2001], v[2001];
int memo[2001][2001];
int c, n;

vector<int> res;

int dp(int id, int remW) {
    if (id == n || remW == 0)
        return 0;
    int& ans = memo[id][remW];
    if (ans) 
        return ans;
    
    if (remW >= w[id])
        return ans = max(dp(id + 1, remW - w[id]) + v[id], dp(id + 1, remW));
    return ans = dp(id + 1, remW);
}

void select_dp(int id, int remW) {
    if (id == n || remW == 0)
        return;
    if (remW >= w[id] && dp(id + 1, remW - w[id]) + v[id] == memo[id][remW]) {
        res.push_back(id);
        select_dp(id + 1, remW - w[id]);
    } else {
        select_dp(id + 1, remW);
    }
}

int main() {
    while (cin >> c >> n) {
        for (int i = 0; i < n; ++i)
            cin >> v[i] >> w[i];
        dp(0, c);
        select_dp(0, c);
        cout << res.size() << endl;
        for (auto x : res)
            cout << x << " ";
        cout << endl;
        memset(memo, 0, sizeof(memo));
        res.clear();
    }    
    return 0;
}