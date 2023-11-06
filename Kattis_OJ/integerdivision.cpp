#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, d;
    cin >> n >> d;
    
    ll x;
    unordered_map<ll, vector<ll>> q;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        q[x / d].push_back(x);
    }    

    ll ans = 0;
    for (auto x : q) {
        ans += x.second.size() * (x.second.size() - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}