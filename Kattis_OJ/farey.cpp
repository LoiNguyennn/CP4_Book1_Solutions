#include <bits/stdc++.h>

#define MAX_N 10001

using namespace std;

int main() {
    int EulerPhi[MAX_N];
    for (int i = 0; i < MAX_N; ++i) EulerPhi[i] = i;
    for (int i = 2; i < MAX_N; ++i) 
        if (EulerPhi[i] == i) 
            for (int j = i; j < MAX_N; j += i)
                EulerPhi[j] -= EulerPhi[j] / i;
    
    int dp[MAX_N] = {0};
    
    dp[1] = 2;

    for (int i = 2; i < MAX_N; ++i) {
        dp[i] = EulerPhi[i] + dp[i - 1];
    }

    int TC;
    cin >> TC;
    while (TC--) {
        int k, n;
        cin >> k >> n;
        cout << k << " " << dp[n] << endl;
    }    
    return 0;
}