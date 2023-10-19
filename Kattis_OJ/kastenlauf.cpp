#include <iostream>
#include <vector>

#define MAX 20 * 50

using namespace std;

int getDist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        n += 2;
        vector<pair<int, int>> loc(n);
        for (int i = 0; i < n; ++i)
            cin >> loc[i].first >> loc[i].second;

        bool AM[n][n];    

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int dist = getDist(loc[i], loc[j]);
                if (dist <= MAX)
                    AM[i][j] = true;
                else
                    AM[i][j] = false;
            }
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    AM[i][j] |= (AM[i][k] & AM[k][j]);
                }
            }
        }

        if (AM[0][n - 1])
            cout << "happy\n";
        else
            cout << "sad\n";
    }
    return 0;
}