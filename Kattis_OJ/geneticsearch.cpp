#include <bits/stdc++.h>

using namespace std;

int b[1000];

int kmp(string p, string t) {
    int j = -1, i = 0;
    b[0] = -1;
    while (i < p.size()) {
        while (j >= 0 && p[j] != p[i]) j = b[j];
        ++j; ++i;
        b[i] = j;
    }

    i = 0, j = 0;
    int num_match = 0;
    while (i < t.size()) {
        while (j >= 0 && t[i] != p[j]) j = b[j];
        ++i; ++j;
        if (j == p.size()) {
            ++num_match;
            j = b[j];
        }
    }
    return num_match;
}

int main() {
    string p, t;
    while (cin >> p && p != "0") {
        cin >> t;

        
        unordered_set<string> type2, type3;
        string c = "AGCT";

        for (int i = 0; i < p.size(); ++i)
            type2.insert(p.substr(0, i) + p.substr(i + 1));
        for (int i = 0; i <= p.size(); ++i)
            for (int j = 0; j < c.size(); ++j)
                type3.insert(p.substr(0, i) + c[j] + p.substr(i));

        int ans1 = kmp(p, t);
        int ans2 = 0, ans3 = 0;
        for (string x : type2) 
            ans2 += kmp(x, t);

        for (string x : type3) 
            ans3 += kmp(x, t);
        

        cout << ans1 << " " << ans2 << " " << ans3 << endl;
    }  
    return 0;
}