#include <bits/stdc++.h>

using namespace std;

int back[200000];

void kmp_preprocessing(string p) {
    int j = -1, i = 0;
    back[0] = -1;
    while (i < p.size()) {
        while (j >= 0 && p[j] != p[i]) j = back[j];
        ++j; ++i;
        back[i] = j;
    }
}

int kmp_search(string p, string t) {
    int j = 0, i = 0;
    int num_match = 0;
    while (i < t.size()) {
        while (j >= 0 && t[i] != p[j]) j = back[j];
        ++i; ++j;
        if (j == p.size()) {
            ++num_match;  
            j = back[j];      
        }
    }
    return num_match;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        string p;
        cin >> p;

        string t = p + p;

        kmp_preprocessing(p);
        cout << p.size() / (kmp_search(p, t) - 1) << endl;
        if (TC) cout << endl;
    }   
    return 0;
}