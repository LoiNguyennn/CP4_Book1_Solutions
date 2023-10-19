#include <bits/stdc++.h>

using namespace std;

bool cmp(string a, string b) {
    int i = a.length(), j = b.length();
    while (i >= 0 && j >= 0) {
        if (a[i] < b[j]) return true;
        if (a[i] > b[j]) return false;
        --i;
        --j;
    }
    if (i == -1) return true;
    return false;
}

int main() {
    string s;
    int t = 0;
    while (getline(cin, s)) {
        if (t) cout << endl;
        ++t;
        int mx = s.length();
        vector<string> v;
        v.push_back(s);
        while (getline(cin, s) && s.length() != 0) {
            v.push_back(s);
            int n = s.length();
            mx = max(mx, n);
        }

        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); ++i) 
            cout << setw(mx) << v[i] << endl;
        
    }
    return 0;
}