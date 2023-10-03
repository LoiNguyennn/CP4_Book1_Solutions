#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    vector<char> L, L_id;
    vector<int> p;
    L.assign(n, 0), L_id.assign(n, 0);
    p.assign(n, -1);

    int k = 0, end = 0;
    for (int i = 0; i < s.size(); ++i) {
        int pos = lower_bound(L.begin(), L.begin() + k, s[i]) - L.begin();
        L[pos] = s[i];
        L_id[pos] = i;
        if (pos == k)
            ++k;
    }
    cout << 26 - k << endl;
    return 0;
}