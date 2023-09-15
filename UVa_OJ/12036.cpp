#include <iostream>
#include <vector>

using namespace std;

int main() {
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; ++tc) {
        vector<int> cnt(101, 0);
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int k;
                cin >> k;
                ++cnt[k];
            }
        }
        bool possible = true;
        for (int i = 0; i < 101; ++i) {
            if (cnt[i] > n) {
                possible = false;
                break;
            }
        }
        cout << "Case " << tc << ": ";
        if (possible) cout << "yes\n";
        else cout << "no\n";
    }
    return 0;
}