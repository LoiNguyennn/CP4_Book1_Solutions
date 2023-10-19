#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, ans = 0, inf = 1e9;
ll w[1000], memo_f[1000][2001], memo_ks[1000][2001];

ll f(int id, int sum) {
    if (sum >= 2000)
        return inf;
    if (id == n) 
        return abs(sum - 1000);

    ll& ans = memo_f[id][sum];
    if (ans != -1) return ans;
    return ans = min(f(id + 1, sum + w[id]), f(id + 1, sum));
}

ll knap_sack(int id, int weight) {
    if (id == n)
        return weight;
    ll& ans = memo_ks[id][weight];
    if (ans != -1)
        return ans;
    if (weight >= w[id])
        return ans = min(knap_sack(id + 1, weight - w[id]), knap_sack(id + 1, weight));
    return ans = knap_sack(id + 1, weight);
}

int main() {
    memset(memo_f, -1, sizeof(memo_f));
    memset(memo_ks, -1, sizeof(memo_ks));
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> w[i];
    ll min_diff = f(0, 0);
    if (knap_sack(0, 1000 + min_diff) == 0)
        cout << 1000 + min_diff << endl;
    else 
        cout << 1000 - min_diff << endl;
    return 0;
}