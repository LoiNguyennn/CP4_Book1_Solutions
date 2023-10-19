#include <bits/stdc++.h>

using namespace std;

int main() {
    int w, p;
    cin >> w >> p;
    vector<int> v;
    v.push_back(0);

    for (int i = 0; i < p; ++i) {
        int t;
        cin >> t;
        v.push_back(t);
    }
    v.push_back(w);

    set<int> dist;
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j)
            dist.insert({v[j] - v[i]});
    }

    for (auto x : dist)
        cout << x << " ";
    return 0;
}