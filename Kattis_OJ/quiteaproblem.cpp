#include <bits/stdc++.h>

using namespace std;

int b[2010];
string T, P = "problem";

void KMP_Preprocessing() {
    int j = -1, i = 0;
    b[0] = -1;
    while (i < P.size()) {
        while (j >= 0 && P[i] != P[j]) j = b[j];
        ++i; ++j;
        b[i] = j;
    }
}

bool KMP_Search() {
    int j = 0, i = 0;
    while (i < T.size()) {
        while (j >= 0 && T[i] != P[j]) j = b[j];
        ++i; ++j;
        if (j == P.size()) return true;
    }
    return false;
}

int main() {
    KMP_Preprocessing();
    while (getline(cin, T)) {
        for (int i = 0; i < T.size(); ++i)
            if (T[i] >= 'A' && T[i] <= 'Z')
                T[i] += 'a' - 'A';
        if (KMP_Search()) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}