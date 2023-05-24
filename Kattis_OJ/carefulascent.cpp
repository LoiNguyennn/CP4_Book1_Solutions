#include <bits/stdc++.h>

#define EPS 1e-10

using namespace std;

struct Shields {
    double l, u, f;
};

vector<Shields> s;
double x, y, n;


double compute(double v) {
    double S = 0;
    double total = 0;
    for (int i = 0; i < s.size(); ++i) {
        total += s[i].u - s[i].l;
        S += (s[i].u - s[i].l) * v * s[i].f;
    }
    S += (y - total) * v;
    return S;
}

int main() {
    cin >> x >> y >> n;
    for (int i = 0; i < n; ++i) {
        Shields a;
        cin >> a.l >> a.u >> a.f;
        s.push_back(a);
    }

    double lo = 0, hi = 10000000000;
    for (int i = 0; i < 100; ++i) {
        double mi = (lo + hi) / 2;
        double S = compute(mi);
        if (S < fabs(x)) {
            lo = mi;
        } else {
            hi = mi;
        }
    }
    if (x > 0)
        cout << fixed << setprecision(11) << lo << endl;
    else 
        cout << fixed << setprecision(11) << -lo << endl;
    return 0;
}