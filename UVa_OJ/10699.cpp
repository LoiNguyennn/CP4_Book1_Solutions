#include <bits/stdc++.h>

#define MAX_N 10000

using namespace std;

vector<int> p;
bitset<10000> bs;

void sieve() {
    bs.set();
    bs[0] = bs[1] = 0;
    for (int i = 2; i < MAX_N; ++i) {
        if (bs[i]) {
            for (int j = i * i; j < MAX_N; j += i) 
                bs[j] = 0;
            p.push_back(i);
        }
    }
}

int numDiffPF(int N) {
    int ans = 0;
    for (int i = 0; i < p.size() && p[i] * p[i] <= N; ++i) {
        if (N % p[i] == 0) ++ans;
        while (N % p[i] == 0) N /= p[i];
    }
    return ans + (N != 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int N;
    sieve();
    while (cin >> N && N) {
        cout << N << " : " << numDiffPF(N) << endl;
    }
    return 0;
}