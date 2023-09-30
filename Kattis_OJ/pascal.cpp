#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

typedef long long ll;

bitset<100000> bs;
vector<ll> p;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i < 100000; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j < 10000; j += i)
                bs[j] = 0;
            p.push_back(i);
        }
    }
}

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "0\n";
        return 0;
    }
    sieve();
    for (ll i : p) {
        if (n % i == 0) {
            cout << n - n / i << endl;
            return 0;
        }
    }
    cout << n - 1 << endl;
    return 0;
}