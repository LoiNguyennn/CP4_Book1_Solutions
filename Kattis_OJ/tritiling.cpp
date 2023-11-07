#include <bits/stdc++.h>

using namespace std;

int main() {
    int f[31], g[31];
    f[0] = 1;
    f[1] = 0;
    f[2] = 3;

    g[0] = 0;
    g[1] = 1;
    g[2] = 0;

    for (int i = 2; i <= 30; ++i) {
        f[i] = f[i - 2] + (g[i - 1] << 1);
        g[i] = f[i - 1] + g[i - 2];
    }

    int n;
    while (cin >> n) {
        if (n == -1) break;
        cout << f[n] << endl;

    }   
    return 0;
}