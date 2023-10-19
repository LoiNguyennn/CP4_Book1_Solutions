#include <bits/stdc++.h>

using namespace std;

int main() {
    
    double a, d;
    cin >> a >> d;
    vector<pair<double, double>> ascent, descent;

    double total_high = 0;
    double as_time = 0, ds_time = 0;

    for (int i = 0; i < a; ++i) {
        double t1, t2;
        cin >> t1 >> t2;
        ascent.push_back({t1, t2});
        total_high += t1;
        as_time += t2;
    }
    for (int i = 0; i < d; ++i) {
        double t1, t2;
        cin >> t1 >> t2;
        descent.push_back({t1, t2});
        ds_time += t2;
    }

    double l = 0, r = max(as_time, ds_time);
    for (int i = 0; i < 100; ++i) {
        double mid = (l + r) / 2;
        double ascent_high = 0, descent_high = total_high;
        double t = mid;

        for (auto x : ascent) {
            if (t >= x.second) {
                ascent_high += x.first;
                t -= x.second;
            } else {
                ascent_high += x.first * t / x.second;
                break;
            }
        }

        t = mid;

        for (auto x : descent) {
            if (t >= x.second) {
                descent_high -= x.first;
                t -= x.second;
            } else {
                descent_high -= x.first * t / x.second;
                break;
            }
        }

        if (ascent_high >= descent_high) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(6) << l << endl;
    return 0;
}