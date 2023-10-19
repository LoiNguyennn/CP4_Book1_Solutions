#include <bits/stdc++.h>

using namespace std;

int main() {
    int p[5];
    int max_point = 0;
    int winner = 0;
    for (int i = 0; i < 5; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        p[i] = a + b + c + d;
        if (p[i] > max_point) {
            max_point = p[i];
            winner = i;
        }
    }
    cout << winner + 1 << " " << max_point << endl;
    return 0;
}