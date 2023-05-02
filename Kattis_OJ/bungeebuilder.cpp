#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

stack<pair<int, int>> s;
int ans = 0;

void solve(int h[], int n, int i) {
    int t = 0; // max height can get if the bridge at position i
    while (!s.empty() && h[i] >= s.top().first) {
        t = max(h[i] - s.top().first + s.top().second, t);
        s.pop();
    }
    s.push(make_pair(h[i], t));    
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int h[n];
    int max_pos = 0, max_height = -1;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        if (h[i] > max_height) {
            max_height = h[i];
            max_pos = i;
        }
    }

    s.push({max_height, 0});
    for (int i = max_pos - 1; i >= 0; --i)
        solve(h, n, i);
    int ans = 0;
    while (!s.empty()) {
        ans = max(ans, s.top().second);
        s.pop();
    }
    s.push({max_height, 0});
    for (int i = max_pos + 1; i < n; ++i)
        solve(h, n, i);
    while (!s.empty()) {
        ans = max(ans, s.top().second);
        s.pop();
    }
    cout << ans << endl;   
    return 0;
}
