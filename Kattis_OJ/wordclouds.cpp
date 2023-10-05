#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> words;
int n, c;
int memo[5050];
const int INF = 1e9;

int dp(int i) {
    if (i >= n) return 0;
    int current_h = 0, current_w = 0;
    int& ans = memo[i];
    if (ans != -1) return ans;
    ans = INF;
    for (int j = i; j < n; ++j) {
        current_h = max(current_h, words[j].second);
        current_w += words[j].first;
        if (current_w > c) break;
        ans = min(ans, current_h + dp(j + 1));
    }
    return ans;
}

int main() {
    cin >> n >> c;
    words.resize(n);
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < n; ++i) {
        cin >> words[i].first >> words[i].second;
    }
    cout << dp(0) << endl;

    return 0;
}