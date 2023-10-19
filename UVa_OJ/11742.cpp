#include <bits/stdc++.h>

using namespace std;

struct constraints {
    int a, b, c;
};

int main() {
    int n, m;
    while (cin >> n >> m) {
        if (m == 0 && n == 0) break;
        constraints cons[m];
        int p[n];
        for (int i = 0; i < n; ++i)
            p[i] = i;
        for (int i = 0; i < m; ++i) 
            cin >> cons[i].a >> cons[i].b >> cons[i].c;
        
        int ans = 0;
        do {
            int notSatisfy = false;
            for (int i = 0; i < m; ++i) {
                int p1, p2;
                for (int j = 0; j < n; ++j) {
                    if (p[j] == cons[i].a)
                        p1 = j;
                    else if (p[j] == cons[i].b)
                        p2 = j;
                }
                if (cons[i].c < 0 && abs(p1 - p2) < -cons[i].c) {
                    notSatisfy = true;
                } else if (cons[i].c > 0 && abs(p1 - p2) > cons[i].c) {
                    notSatisfy = true;
                }
            }
            if (!notSatisfy)
                ++ans;
        } while (next_permutation(p, p + n));
        cout << ans << endl;
    }
    return 0;
}