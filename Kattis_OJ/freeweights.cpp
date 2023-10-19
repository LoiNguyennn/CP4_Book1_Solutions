#include <bits/stdc++.h>

using namespace std;

vector<int> r1, r2;

bool check(int x) {
    int last_pos = -1;
    for (int i = 0; i < r1.size(); ++i) {
        if (r1[i] > x) {
            if (last_pos == -1)
                last_pos = i;
            else if (r1[last_pos] != r1[i])
                return false;
            else
                last_pos = -1;
        }
    }

    last_pos = -1;
    for (int i = 0; i < r2.size(); ++i) {
        if (r2[i] > x) {
            if (last_pos == -1)
                last_pos = i;
            else if (r2[last_pos] != r2[i])
                return false;
            else
                last_pos = -1;
        }
    }
    return (last_pos == -1);
}    

int main() {
    int n;
    cin >> n;
    r1.reserve(n);
    r2.reserve(n);

    vector<int> sorted;
    sorted.reserve(n + 1);

    int t;
    set<int> s;
    s.insert(0);

    for (int i = 0; i < n; ++i) {
        cin >> t;
        r1.push_back(t);
        s.insert(t);
    }
    for (int i = 0; i < n; ++i) {
        cin >> t;
        r2.push_back(t);
        s.insert(t);
    }

    for (auto x : s) {
        sorted.push_back(x);
    }

    int lo = 0, hi = n;

    int idx;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        if (check(sorted[mi])) {
            idx = mi;
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }
    cout << sorted[idx] << endl;
    return 0;
}