#include <bits/stdc++.h>

using namespace std;

int n, inf = 1e9, price;
int v[100], memo_ks[100][11000], memo_cc[100][11000];

int dp_knapsack(int id, int sum) {
    if (sum >= price) return sum;
    if (id == n) return inf;
    int& ans = memo_ks[id][sum];
    if (ans) return ans;
    return ans = min(dp_knapsack(id + 1, sum + v[id]), dp_knapsack(id + 1, sum));
}

int dp_coinchange(int id, int remV) {
    if (remV == 0) return 0;
    if (id == n || remV < 0) return inf;
    int& ans = memo_cc[id][remV];
    if (ans) return ans;
    return ans = min(dp_coinchange(id + 1, remV - v[id]) + 1, dp_coinchange(id + 1, remV));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC;

    while (TC--) {
        cin >> price >> n;
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        int total = dp_knapsack(0, 0);
        int numcoin = dp_coinchange(0, total);
        cout << total << " " << numcoin << endl;
        memset(memo_ks, 0, sizeof(memo_ks));
        memset(memo_cc, 0, sizeof(memo_cc));
    }
    return 0;
}