#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m, a, c, x0;
ll x[1000001];

int BinarySearch(int i) {
    int l = 1, r = n;
    while (l <= r) {
        int m = (l + r) / 2;
        if (i == x[m])
            return m;
        else if (i < x[m])
            r = m - 1;
        else 
            l = m + 1;
    }
    return -1;
}

int main() {
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> a >> c >> x0;
    x[1] = (a * x0 + c) % m;
    for (int i = 2; i <= n; ++i)
        x[i] = (a * x[i - 1] + c) % m;
    
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (BinarySearch(x[i]) > 0)
            ++ans;
    }
    cout << ans << endl;
    return 0;
}