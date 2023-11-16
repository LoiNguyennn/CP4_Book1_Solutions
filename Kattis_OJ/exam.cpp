#include <bits/stdc++.h>

using namespace std;

string a, b;
int n; 

int main() {
    int k;
    cin >> k;
    cin >> a >> b;

    n = a.size();

    int match = 0;
    for (int i = 0; i < n; ++i)
        match += a[i] == b[i];

    cout << min(n - match, n - k) + min(match, k) << endl;
    return 0;
}