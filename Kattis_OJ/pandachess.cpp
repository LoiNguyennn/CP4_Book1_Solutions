#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

unordered_map<ll, vector<ll>> AL;
unordered_map<ll, ll> visited;
vector<ll> topo;

void dfs(ll u) {
    visited[u] = 1;
    for (ll v : AL[u])
        if (!visited[v])
            dfs(v);
    topo.push_back(u);
}

int main() {
    ll n, m, d;
    cin >> n >> m >> d;

    vector<ll> ICs;
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        AL[a].push_back(b);
        ICs.push_back(a);
        ICs.push_back(b);
    }

    for (auto x : ICs) 
        if (!visited[x])
            dfs(x);

    reverse(topo.begin(), topo.end());

    unordered_map<ll, ll> ranked;
    for (int i = 0; i < topo.size(); ++i)
        ranked[topo[i]] = i + 1;

    vector<ll> v;
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        if (ranked[x] == 0) continue;
        v.push_back(ranked[x]);
    }

    ll k = 0;
    vector<ll> LIS(n, -1);
    for (int i = 0; i < v.size(); ++i) {
        int pos = lower_bound(LIS.begin(), LIS.begin() + k, v[i]) - LIS.begin();
        LIS[pos] = v[i];
        if (pos == k) ++k;
    }

    cout << 2 * (n - k) << endl;
    return 0;
}