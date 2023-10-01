#include <bits/stdc++.h>

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

int numPF(int n) {
    int ans = 0;
    for (int i = 0; i < p.size() && p[i] * p[i] <= n; ++i) {
        while (n % p[i] == 0) {
            ++ans;
            n /= p[i];
        }
    }
    if (n != 1) ++ans;
    return ans;
}

vector<pair<int, int>> v;

int main() {
    sieve();
    v.resize(2000001);
    v[0].first = 0;
    for (int i = 1; i < 2000001; ++i) {
        v[i].second = i;
        v[i].first = numPF(i);
    }
    sort(v.begin(), v.end());
    int n;
    int tc = 1;
    while (cin >> n) {
        if (n == 0) break;
        cout << "Case " << tc++ << ": " << v[n].second << endl;
    }
    return 0;
}