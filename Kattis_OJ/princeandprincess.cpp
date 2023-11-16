#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC;
    cin >> TC;
    for (int t = 1; t <= TC; ++t) {
        int n, p, q;
        cin >> n >> p >> q;

        unordered_map<int, int> order;
        for (int i = 1; i <= p + 1; ++i) {
            int x;
            cin >> x;
            order[x] = i;
        }

        vector<int> v;
        for (int i = 1; i <= q + 1; ++i) {
            int x;
            cin >> x;
            if (order[x] == 0) continue;
            v.push_back(order[x]);
        }

        int ans = 0;
        vector<int> LIS(v.size(), -1);
        for (int i = 0; i < v.size(); ++i) {
            int pos = lower_bound(LIS.begin(), LIS.begin() + ans, v[i]) - LIS.begin();
            LIS[pos] = v[i];
            if (pos == ans) ++ans;
        }
        cout << "Case " << t << ": " << ans << endl;
    }   
    return 0;
}