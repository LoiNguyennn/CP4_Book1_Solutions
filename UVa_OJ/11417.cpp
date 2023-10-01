#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

int main() {
    int n;
    while (cin >> n && n) {
        ll G = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                G += gcd(i, j);
            }
        }
        cout << G << endl;
    }
    return 0;
}