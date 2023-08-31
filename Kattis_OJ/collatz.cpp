#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long ll;

int main() {
    ll a, b;
    while (cin >> a >> b) {
        if (a == 0) break;

        int A = a, B = b;
        unordered_map<int, int> sequenceA;
        int i = 0;
        sequenceA[a] = i++;
        while (a != 1) {
            if (a % 2 == 0)
                a = (a >> 1);
            else
                a = (3 * a + 1);
            sequenceA[a] = i++;
        }

        i = 0;
        if (sequenceA.count(b)) {
            cout << A << " needs " << sequenceA[b] << " steps, " << B << " needs " << i << " steps, they meet at " << b << endl;
            continue;
        }
        while (b != 1) {
            if (b % 2 == 0)
                b = (b >> 1);
            else
                b = (3 * b + 1);
            ++i;
            if (sequenceA.count(b)) {
                cout << A << " needs " << sequenceA[b] << " steps, " << B << " needs " << i << " steps, they meet at " << b << endl;
                break;
            }
        }
    }
       
    return 0;
}