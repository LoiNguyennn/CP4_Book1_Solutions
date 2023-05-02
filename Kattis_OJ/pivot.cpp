#include <iostream>

using namespace std;

int code[26] = {0};
int guess[26] = {0};

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int prefix_max[n];
    prefix_max[0] = a[0];
    for (int i = 1; i < n; ++i)
        prefix_max[i] = max(prefix_max[i - 1], a[i]);
    
    int postfix_min[n];
    postfix_min[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        postfix_min[i] = min(a[i], postfix_min[i + 1]);
    
    int ans = 0;
    for (int i = 0; i < n; ++i)
        if (prefix_max[i] <= a[i] && postfix_min[i] >= a[i]) ++ans;
    cout << ans << endl;
    return 0;
}