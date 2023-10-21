#include <bits/stdc++.h>

#define MAX_N ((int(1e6) << 1))

using namespace std;

typedef long long ll;
bitset<10000010> bs;
vector<int> p;

int numDiffPF[MAX_N + 1], numDiv[MAX_N + 1];
int n;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i * i <= MAX_N; ++i) {
        if (bs[i]) {
            for (ll j = i * i; j <= MAX_N; j += i)
                bs[j] = 0;
            p.push_back(i);
        }
    }
}

int main() {
    for (int i = 2; i <= MAX_N; ++i) 
        if (numDiffPF[i] == 0) 
            for (int j = i; j <= MAX_N; j += i) 
                ++numDiffPF[j];

    for (int i = 1; i <= MAX_N; ++i) {
        for (int j = i; j <= MAX_N; j += i)
            ++numDiv[j];
    }
    sieve();
    int TC;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%d", &n);
        printf("%d\n", numDiv[n] - numDiffPF[n]);
    }
    return 0;
}