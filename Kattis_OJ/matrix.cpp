#include <iostream>

using namespace std;

int main() {
    int tc = 1;   
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        cout << "Case " << tc++ << ":\n";
        int det = a * d - c * b;
        int c11 = d, c12 = -c, c21 = -b, c22 = a;
        cout << c11 / det << " " << c21 / det << endl;
        cout << c12 / det << " " << c22 / det << endl;
    }
    return 0;
}