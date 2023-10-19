#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree<tuple<int, int, int>, null_type, greater<tuple<int, int, int>>, rb_tree_tag, tree_order_statistics_node_update> ost;

int main() {
    ost T;
    int n, m;
    cin >> n >> m;
    pair<int, int> teams[n + 1];
    for (int i = 1; i <= n; ++i) {
        teams[i] = make_pair(0, 0);
        T.insert(make_tuple(teams[i].first, -teams[i].second, -i));
    }
    for (int i = 0; i < m; ++i) {
        int t, p;
        cin >> t >> p;
        T.erase(make_tuple(teams[t].first, -teams[t].second, -t));
        ++teams[t].first;
        teams[t].second += p; 
        T.insert(make_tuple(teams[t].first, -teams[t].second, -t));
        cout << T.order_of_key(make_tuple(teams[1].first, -teams[1].second, -1)) + 1 << endl;
    }
    return 0;
}