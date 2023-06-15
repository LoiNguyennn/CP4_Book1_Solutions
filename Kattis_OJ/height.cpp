#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
    int P;
    cin >> P;
    while (P--) {
        int k;
        cin >> k;
        int a[20];
        memset(a, 0, sizeof(a));
        int ans = 0;
        cin >> a[0];
        for (int i = 1; i < 20; ++i) {
            int t;
            cin >> t;
            int j = 0;
            while (j < i && a[j] < t)
                ++j;
            if (j == i) {
                a[j] = t;
                continue;
            }
            ans += i - j;
            for (int u = i; u > j; --u) {
                a[u] = a[u - 1];
            }
            a[j] = t;
        }
        cout << k << " " << ans << endl;
    } 
    return 0;
}