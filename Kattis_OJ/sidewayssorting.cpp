#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
    for (int i = 0; i < a.length(); ++i)
        if (a[i] <= 'Z') a[i] += 'a' - 'A';
    for (int i = 0; i < b.length(); ++i)
        if (b[i] <= 'Z') b[i] += 'a' - 'A';
    return a < b;
}

int main() {
    int r, c;
    while (cin >> r >> c) {
        if (r == 0 && c == 0) break;
        char a[r + 5][c + 5];
        for (int i = 0; i < r; ++i)
            cin >> a[i];

        char trans[c + 5][r + 5];
        for (int i = 0; i < c; ++i) {
            for (int j = 0; j < r; ++j) {
                trans[i][j] = a[j][i];
            }
            trans[i][r] = '\0';
        }

        vector<string> v;
        for (int i = 0; i < c; ++i) {
            string s(trans[i]);
            v.push_back(s);
        }

        stable_sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < v.size(); ++j)
                cout << v[j][i];
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}