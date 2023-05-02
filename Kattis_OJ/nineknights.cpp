#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int moveX[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int moveY[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool valid(int i, int j, char a[][5]) {
    for (int u = 0; u < 8; ++u) {
        int tmp1 = i + moveX[u];
        int tmp2 = j + moveY[u];
        if (tmp1 >= 0 && tmp2 >= 0 && tmp1 < 5 && tmp2 < 5 && a[tmp1][tmp2] == 'k')
            return false;
    }
    return true;
}

int main() {
    char a[5][5];
    int cnt = 0;
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j) {
            cin >> a[i][j];
            if (a[i][j] == 'k') ++cnt;
        }
    if (cnt != 9) {
        cout << "invalid\n";
        return 0;
    }
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j) {
            if (a[i][j] == 'k')
                if (!valid(i, j, a)) {
                    cout << "invalid\n";
                    return 0;
                }
        }
    cout << "valid\n";
    return 0;
}