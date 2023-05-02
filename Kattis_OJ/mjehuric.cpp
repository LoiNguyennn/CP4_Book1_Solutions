#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
    int a[5];
    for (int i = 0; i < 5; ++i) cin >> a[i];
    while (true) {
        bool flag = false;
        for (int i = 0; i < 4; ++i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                for (int j = 0; j < 5; ++j)
                    cout << a[j] << " ";
                cout << endl;
                flag = true;
            }
        }
        if (!flag) break;
    }
    return 0;
}