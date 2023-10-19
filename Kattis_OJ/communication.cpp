#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> mp;
    for (int i = 0; i < 256; ++i) {
        int t = (i ^ (i << 1)) & 255;
        mp[t] = i;
    }

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cout << mp[a] << " ";
    }
    return 0;
}