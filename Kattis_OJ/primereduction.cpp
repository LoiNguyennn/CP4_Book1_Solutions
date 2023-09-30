#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

typedef long long ll;

bitset<100000> bs;
vector<ll> p, factors;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < 100000; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j < 100000; j += i) {
                bs[j] = 0;
            }
            p.push_back(i);
        }
    }
}

ll fact(int n) {
    ll total = 0;
    for (int i = 0; i < p.size() && p[i] * p[i] <= n; ++i) {
        while (n % p[i] == 0) {
            n /= p[i];
            factors.push_back(p[i]);
            total += p[i];
        }
    }
    if (n != 1) {
        factors.push_back(n);
        total += n;
    }
    return total;
}

int main() {
    int n;
    sieve();
    while (cin >> n) {
        if (n == 4) break;
        int cnt = 0;
        while (true) {
            factors.clear();
            n = fact(n);
            ++cnt;
            if (factors.size() == 1) {
                cout << n << " " << cnt << endl;
                break;
            }
        }
    }
    return 0;
}