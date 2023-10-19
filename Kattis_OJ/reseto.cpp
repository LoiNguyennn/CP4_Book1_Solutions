#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bitset<100001> bs;
int n, k;

ll sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    ll cnt = 0;
    for (ll i = 2; i <= n; ++i) {
        if (bs[i]) {
            bs[i] = 0;
            ++cnt;
            if (cnt == k) return i;
            for (ll j = i; j <= n; j += i) {
                if (bs[j] == 0) continue;
                bs[j] = 0;
                ++cnt;
                if (cnt == k) return j;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    
    cin >> n >> k;
    cout << sieve() << endl;
    return 0;
}