#include <bits/stdc++.h>

#define MAXN int(10000000)

using namespace std;

int back[MAXN];
string p, t;

void kmp() {
    int j = -1, i = 0;
    back[0] = -1;
    while (i < p.size()) {
        while (j >= 0 && p[i] != p[j]) j = back[j];
        ++i; ++j;
        back[i] = j;
    }

    i = j = 0;
    while (i < t.size()) {
        while (j >= 0 && t[i] != p[j]) j = back[j];
        ++i; ++j;
        if (j == p.size()) {
            cout << i - j << " ";
            j = back[j];
        }
    }
}

int main() {
    while (getline(cin, p) && getline(cin, t)) {
        kmp();
        cout << endl;
    }
    return 0;
}