#include <bits/stdc++.h>

#define MAX_N 100005

using namespace std;

typedef long long ll;

ll numDiv[MAX_N], sumDiv[MAX_N];

int main() {
    for (ll i = 1; i <= MAX_N; ++i)
        for (ll j = i; j <= MAX_N; j += i) {
            ++numDiv[j];
            sumDiv[j] += i;
        }
        
    int TC;
    cin >> TC;
    while (TC--) {
        int a, b, k;
        cin >> a >> b >> k;
        int i = a;
        while (i % k)
            ++i;
        ll g = 0, h = 0;
        while (i <= b) {
            g += numDiv[i];
            h += sumDiv[i];
            i += k;
        }
        cout << g << " " << h << endl;
    }    
    return 0;
}