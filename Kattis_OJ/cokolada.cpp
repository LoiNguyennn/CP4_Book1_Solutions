#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x;
    cin >> x;
    int k = ceil(log2(x)); 
    cout << (1 << k) << " " << k - __builtin_ctz(x) << endl;
    return 0;
}