#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 1;
    while (true) {
        int a[32];
        for (int i = 0; i < 32; ++i)
            a[i] = -1;
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; ++i) {
            string ins;
            cin >> ins;
            if (ins == "SET") {
                int t;
                cin >> t;
                a[t] = 1;
            } else if (ins == "CLEAR") {
                int t;
                cin >> t;
                a[t] = 0;
            } else if (ins == "OR") {
                int t1, t2;
                cin >> t1 >> t2;
                if (a[t1] == 1 || a[t2] == 1)
                    a[t1] = 1;
                else if (a[t1] == 0 && a[t2] == 0)
                    a[t1] = 0;
                else 
                    a[t1] = -1;
            } else {
                int t1, t2;
                cin >> t1 >> t2;
                if (a[t1] == 0 || a[t2] == 0)
                    a[t1] = 0;
                else if (a[t1] == 1 && a[t2] == 1)
                    a[t1] = 1;
                else 
                    a[t1] = -1;
            }
        }
        for (int i = 31; i >= 0; --i) {
            if (a[i] == -1)
                cout << "?";
            else 
                cout << a[i];
        }
        cout << "\n";
    }
    return 0;
}