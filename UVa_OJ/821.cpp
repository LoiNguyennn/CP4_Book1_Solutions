#include <iostream>
#include <iomanip>

#define inf 1e9

using namespace std;

int main() {
    int a, b;
    int tc = 1;
    while (cin >> a >> b) {
        if (a == 0 && b == 0) break;
        int AM[100][100];
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                AM[i][j] = inf;
                if (i == j) AM[i][j] = 0;
            }
        }

        --a; --b;
        AM[a][b] = 1;
        while (cin >> a >> b) {
            if (a == b && b == 0) break;
            --a; --b;
            AM[a][b] = 1;
        }

        for (int k = 0; k < 100; ++k) 
            for (int i = 0; i < 100; ++i)
                for (int j = 0; j < 100; ++j)
                    AM[i][j] = min(AM[i][j], AM[i][k] + AM[k][j]);
        
        int total = 0, cnt = 0;
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                if (i == j)
                    continue;

                if (AM[i][j] != inf) {
                    total += AM[i][j];
                    ++cnt;
                }
            }
        }

        cout << "Case " << tc++ << ": average length between pages = " << fixed << setprecision(3) << double(total) / cnt
        << " clicks" << endl;
    }
    return 0;
}