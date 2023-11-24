#include <bits/stdc++.h>

using namespace std;

string t, p;
int back[100001];

int kmp() {
    int j = -1, i = 0;
    back[0] = -1;
    while (i < p.size()) {
        while (j >= 0 && p[i] != p[j]) j = back[j];
        ++j; ++i;
        back[i] = j;
    }

    i = j = 0;
    while (i < t.size()) {
        while (j >= 0 && t[i] != p[j]) j = back[j];
        ++i; ++j;
        if (j == p.size()) return j;
    }
    return j;
}

int main() {
    while (cin >> t) {
        p = t;
        reverse(p.begin(), p.end());
        int i = kmp();
        while (i < p.size()) {
            t += p[i]; 
            ++i;
        }
        cout << t << endl;
    }
    return 0;
}