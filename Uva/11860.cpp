#include <bits/stdc++.h>

using namespace std;

int main() {
    int numTest;
    cin >> numTest;
    cin.ignore();
    
    for (int tc = 1; tc <= numTest; ++tc) {
        unordered_map<string, int> window;
        vector<string> text;
        string s;
        while (getline(cin, s) && s != "END") {
            for (int i = 0; i < s.length(); ++i)
                if (s[i] < 'a' || s[i] > 'z')
                    s[i] = ' ';
            stringstream sin(s);
            string tmp;
            while (sin >> tmp) {
                window.insert({tmp, 0});
                text.push_back(tmp);
            }
        }
        int l = 0;
        int numUni = window.size();
        int curUni = 0;
        int p = 0, q = 0;
        int min_diff = INT_MAX;
        for (int r = 0; r < text.size(); ++r) {
            if (window[text[r]] == 0) 
                ++curUni;
            ++window[text[r]];       
            while (curUni == numUni) {
                if (r - l + 1 < min_diff) {
                    p = l;
                    q = r;
                    min_diff = r - l + 1;
                }
                if (window[text[l]] == 1) 
                    --curUni;
                --window[text[l]];
                ++l;
            }
        }
        cout << "Document " << tc << ": " << p + 1 << " " << q + 1 << endl;
    }
    return 0;
}