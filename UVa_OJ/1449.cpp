#include <bits/stdc++.h>

using namespace std;

int b[1000];

void kmp_preprocessing(string p) {
    int j = -1, i = 0;
    b[0] = -1;
    while (i < p.size()) {
        while (j >= 0 && p[j] != p[i]) j = b[j];
        ++j; ++i;
        b[i] = j;
    }
}

int kmp_search(string p, string t) {
    int j = 0, i = 0;
    int num_match = 0;
    while (i < t.size()) {
        while (j >= 0 && t[i] != p[j]) j = b[j];
        ++j; ++i;
        if (j == p.size()) {
            ++num_match;
            j = b[j];
        }
    }
    return num_match;
}

int main() {
    int n;
    while (cin >> n && n) {
        vector<pair<string, int>> patterns(n);
        for (int i = 0; i < n; ++i)
            cin >> patterns[i].first;
        string text;
        cin >> text;

        int m = INT_MIN;
        
        for (int i = 0; i < n; ++i) {
            kmp_preprocessing(patterns[i].first);
            patterns[i].second = kmp_search(patterns[i].first, text);
            m = max(m, patterns[i].second);
        }

        cout << m << endl;
        for (int i = 0; i < n; ++i)
            if (patterns[i].second == m)
                cout << patterns[i].first << endl;
    }
    return 0;
}