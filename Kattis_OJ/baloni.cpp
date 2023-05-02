#include <iostream>

using namespace std;

int h[1000001] = {0};

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        if (h[k] == 0) {
            ++ans;
            ++h[k - 1];
        } else {
            --h[k];
            ++h[k - 1];
        }
    }
    cout << ans << endl;
    return 0;
}