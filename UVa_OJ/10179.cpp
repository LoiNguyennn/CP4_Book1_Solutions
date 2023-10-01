#include <bits/stdc++.h>

#define MAX_N 100000

using namespace std;

typedef long long ll;

vector<ll> p;
bitset<MAX_N> bs;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < MAX_N; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j < MAX_N; j += i)
                bs[j] = 0;
            p.push_back(i);
        }
    }
}

int EulerPhi(int n) {
    int ans = n;
    for (int i = 0; i < p.size(); ++i) {
        if (n % p[i] == 0) ans = ans - ans / p[i];
        while (n % p[i] == 0) n /= p[i];
    }
    if (n != 1) ans = ans - ans / n;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    sieve();
    while (cin >> n) {
        if (n == 0) break;
        cout << EulerPhi(n) << endl;
    }
    return 0;
}