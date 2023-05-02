#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    while (cin >> n) {
        int mark[n] = {0};
        int tmp1;
        cin >> tmp1;
        for (int i = 1; i < n; ++i) {
            int tmp2;
            cin >> tmp2;
            int t = abs(tmp2 - tmp1);
            if (t >= 0 && t <= n - 1) 
                ++mark[t];
            tmp1 = tmp2;
        }
        bool flag = true;
        for (int i = 1; i < n; ++i)
            if (mark[i] == 0) flag = false;
        if (flag) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }
    return 0;
}