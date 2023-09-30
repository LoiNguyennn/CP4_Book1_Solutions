#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> p;
bitset<100000> bs;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < 100000; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j < 100000; j += i) 
                bs[j] = 0;
            p.push_back(i);
        }
    }
}

int main() {
    ll n;
    sieve();
    while (cin >> n) {
        if (n == 0) break;
        cout << n << " = ";
        bool isNegative = (n < 0);
        n = abs(n);

        vector<int> factors;
        for (int i = 0; i < p.size() && p[i] * p[i] <= n; ++i) {
            while (n % p[i] == 0) {
                factors.push_back(p[i]);
                n /= p[i];
            }
        }

        if (n != 1) factors.push_back(n);

        if (isNegative) cout << "-1 x ";
        for (int i = 0; i < factors.size() - 1; ++i)
            cout << factors[i] << " x ";
        cout << factors[factors.size() - 1] << endl;
    }
    return 0;
}