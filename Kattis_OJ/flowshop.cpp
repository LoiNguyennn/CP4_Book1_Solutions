#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int a[n + 1][m + 1];
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            a[i][j] += max(a[i - 1][j], a[i][j - 1]);
    for (int i = 1; i <= n; ++i) cout << a[i][m] << " ";
    return 0;
}