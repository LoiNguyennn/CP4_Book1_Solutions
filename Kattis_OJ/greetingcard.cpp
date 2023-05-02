#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000000
#define INP() freopen("input.txt", "r", stdin)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int dx[] = {-2018, -1680, -1680, -1118, -1118, 0, 0, 1118, 1118, 1680, 1680, 2018};
int dy[] = {0, -1118, 1118, -1680, 1680, -2018, 2018, -1680, 1680, -1118, 1118, 0};

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    cin >> n;
    int x, y;
    int ans = 0;
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        for (int j = 0; j < 12; ++j) {
            int x2 = x + dx[j];
            int y2 = y + dy[j];
            if (s.find({x2, y2}) != s.end()) 
                ++ans;
        }
        s.insert({x, y});
    }
    cout << ans << endl;
    return 0;
}