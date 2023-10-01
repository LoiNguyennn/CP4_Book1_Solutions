#include <bits/stdc++.h>

#define MAX_N 1000000

typedef long long ll;

using namespace std;

vector<ll> p;
bitset<MAX_N> bs;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < MAX_N; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j < MAX_N; j += i) {
                bs[j] = 0;
            }
            p.push_back(i);
        }
    }
}

int countFactor(int n) {
    int ans = 1;
    for (int i = 0; i < p.size() && p[i] * p[i] <= n; ++i) {
        int exp = 0;
        while (n % p[i] == 0) {
            n /= p[i];
            ++exp;
        }
        ans *= exp + 1;
    }
    if (n != 1) ans *= 2;
    return ans;
}

int main() {
    int TC;
    cin >> TC;
    sieve();
    while (TC--) {
        int L, U;
        cin >> L >> U;
        int P, D = 0;
        for (int i = L; i <= U; ++i) {
            int k = countFactor(i); 
            if (k > D) {
                D = k;
                P = i;
            }
        }
        cout << "Between " << L << " and " << U << ", " << P << " has a maximum of " << D << " divisors.\n";
    }
    return 0;
}