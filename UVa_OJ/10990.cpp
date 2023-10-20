#include <bits/stdc++.h>

#define MAX_N 2000005

using namespace std;

typedef long long ll;

bitset<10000010> bs;
vector<int> p;
int dp[MAX_N], depth[MAX_N], EulerPhi[MAX_N];

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    ll lim = sqrt(MAX_N);
    for (ll i = 2; i <= lim; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j <= lim; j += i)
                bs[j] = 0;
        }
        p.push_back(i);
    }
}

int main() {
    int TC;
    cin >> TC;
    sieve();

    for (int i = 1; i < MAX_N; ++i) EulerPhi[i] = i;

    for (int i = 2; i < MAX_N; ++i)
        if (EulerPhi[i] == i) // i is a prime number
            for (int j = i; j <= MAX_N; j += i)
                EulerPhi[j] = (EulerPhi[j]/i) * (i-1);
         
    dp[0] = dp[1] = 0;
    depth[0] = depth[1] = 0;   
    for (int i = 2; i < MAX_N; ++i) {
        depth[i] = depth[EulerPhi[i]] + 1;
        dp[i] = depth[i] + dp[i - 1];
    }

    while (TC--) {
        int m, n;
        cin >> m >> n;
        cout << dp[n] - dp[m - 1] << endl;
    }
    return 0;
}