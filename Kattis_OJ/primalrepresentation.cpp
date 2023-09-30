#include <iostream>
#include <bitset>
#include <vector>
#include <map>

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
    int N;
    sieve();
    while (cin >> N) {
        if (N < 0) cout << "-1 ";
        N = abs(N);

        map<int, int> factors;
        for (int i = 0; i < p.size() && p[i] * p[i] <= N; ++i) {
            while (N % p[i] == 0) {
                ++factors[p[i]];
                N /= p[i];
            }
        }

        if (N != 1) ++factors[N];
        for (auto x : factors) {
            if (x.second == 1) cout << x.first << " ";
            else cout << x.first << "^" << x.second << " "; 
        }
        cout << endl;
    }
    return 0;
}