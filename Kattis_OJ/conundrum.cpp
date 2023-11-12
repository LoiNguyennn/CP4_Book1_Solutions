#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    string per = "PER";
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != per[i % 3])
            ++ans;
    }   
    cout << ans << endl;
    return 0;
}