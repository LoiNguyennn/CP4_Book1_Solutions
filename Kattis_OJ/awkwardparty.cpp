#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        mp[t].push_back(i);
    }
    int ans = n;
    for (auto it : mp) {
        for (int i = 1; i < it.second.size(); ++i)
            ans = min(ans, it.second[i] - it.second[i - 1]);
    }
    cout << ans << endl;
    return 0;
}