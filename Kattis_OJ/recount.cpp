#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> mp;
    string s;
    int max_freq = 0;
    string ans;
    while (getline(cin, s) && s != "***") {
        ++mp[s];
        if (mp[s] > max_freq) {
            max_freq = mp[s];
            ans = s;
        }
    }
    for (auto x : mp) {
        if (x.second == max_freq && x.first != ans)
            ans = "Runoff!";
    }
    cout << ans << endl;
    return 0;
}