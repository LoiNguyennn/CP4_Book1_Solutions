#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        ost tr;
        int n;
        cin >> n;
        long long sum = 0;
        for (int i = 1; i <= n; ++i) {
            int m;
            cin >> m;
            tr.insert(m);
            if (i % 2 == 0) {
                sum += (*tr.find_by_order(i / 2) + *tr.find_by_order((i - 1) / 2)) / 2;
            } else {
                sum += *tr.find_by_order(i / 2);
            }
        }
        cout << sum << endl;
    }
    return 0;
}