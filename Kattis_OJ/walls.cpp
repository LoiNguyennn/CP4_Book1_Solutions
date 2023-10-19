#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double dist(pair<double, double> a, pair<double, double> b) {
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main() {
    int l, w, n, r;
    cin >> l >> w >> n >> r;

    vector<ll> valid_bm;
    for (int a = 0; a < n; ++a) {
        ll m = 0;
        m |= (1 << a);
        valid_bm.push_back(m);
    }

    for (int a = 0; a < n - 1; ++a) {
        for (int b = a + 1; b < n; ++b) {
            ll m = 0;
            m |= (1 << a);
            m |= (1 << b);
            valid_bm.push_back(m);
        }
    }

    for (int a = 0; a < n - 2; ++a) {
        for (int b = a + 1; b < n - 1; ++b) {
            for (int c = b + 1; c < n; ++c) {
                ll m = 0;
                m |= (1 << a);
                m |= (1 << b);
                m |= (1 << c);
                valid_bm.push_back(m);
            }
        }
    }

    for (int a = 0; a < n - 3; ++a) {
        for (int b = a + 1; b < n - 2; ++b) {
            for (int c = b + 1; c < n - 1; ++c) {
                for (int d = c + 1; d < n; ++d) {
                    ll m = 0;
                    m |= (1 << a);
                    m |= (1 << b);
                    m |= (1 << c);
                    m |= (1 << d);
                    valid_bm.push_back(m);
                }
            }
        }
    }
    
    vector<pair<double, double>> walls;
    walls.push_back({-l / 2.0, 0});
    walls.push_back({l / 2.0, 0});
    walls.push_back({0, -w / 2.0});
    walls.push_back({0, w / 2.0});

    vector<pair<double, double>> cranes;
    vector<ll> mask;
    cranes.reserve(n);
    mask.reserve(n);

    for (ll i = 0; i < n; ++i) {
        pair<double, double> a;
        cin >> a.first >> a.second;

        ll m = 0;
        for (ll j = 0; j < 4; ++j) 
            if (dist(a, walls[j]) <= r)
                m |= (1 << j);
        
        cranes.push_back(a);
        mask.push_back(m);
    }
    
    int ans = INT_MAX;
    for (ll i : valid_bm) {
        ll m = 0;
        int cnt = 0;
        for (ll j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                m |= mask[j];
                ++cnt;
            }
        }

        if (m == 15) 
            ans = min(ans, cnt);
        
    }
    if (ans != INT_MAX)
        cout << ans << endl;
    else 
        cout << "Impossible\n";
    return 0;
}