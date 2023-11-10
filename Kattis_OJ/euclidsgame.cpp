#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        if (a < b) swap(a, b);
        if (a % b == 0 || 1.0 * a / b > 1.618)
            cout << "Stan wins\n";
        else 
            cout << "Ollie wins\n";
    }   
    return 0;
}