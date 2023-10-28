#include <bits/stdc++.h>

using namespace std;

int ExtendedEuclid(int a, int b, int& x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = ExtendedEuclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
}   

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a, b;
    while (cin >> a >> b) {
        int x, y, d;
        d = ExtendedEuclid(a, b, x, y);
        cout << x << " " << y << " " << d << endl;
    }    
    return 0;
}