#include <iostream>
#include <unordered_map>
#include <climits>

using namespace std;

int main() {
    int n, p, m;
    cin >> n >> p >> m;
    string s;
    unordered_map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        mp[s] = 0;
    }

    int max_val = 0;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        int t;
        cin >> t;
        mp[s] += t;
        if (mp[s] > max_val)
            max_val = mp[s];
        if (mp[s] >= p) {
            cout << s << " wins!\n";
            mp[s] = INT_MIN;
        }
    }
    if (max_val < p || max_val == 0)
        cout << "No winner!\n";
    return 0;
}