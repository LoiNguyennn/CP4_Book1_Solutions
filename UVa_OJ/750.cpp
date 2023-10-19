#include <bits/stdc++.h>

using namespace std;

int row[8];

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        for (int i = 0; i < 8; ++i)
            row[i] = i;
        int a, b;
        cin >> a >> b;
        
        int counter = 0;
        do {
            bool valid = true;
            for (int i = 0; i < 8; ++i) 
                for (int j = i + 1; j < 8; ++j) 
                    if (abs(i - j) == abs(row[i] - row[j]))
                        valid = false;
            
            if (valid && row[b - 1] == a - 1) {
                printf("%2d      %d", ++counter, row[0] + 1);
                for (int i = 1; i < 8; ++i) 
                    printf(" %d", row[i] + 1);
                printf("\n");
            }
        } while (next_permutation(row, row + 8));
        if (TC) printf("\n");
    }
    return 0;
}