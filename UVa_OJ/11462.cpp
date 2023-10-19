#include <bits/stdc++.h>

using namespace std;

int cnt[100];

int main() {
    int n;
    while (scanf("%d", &n) && n) {
        int t; 
        for (int i = 0; i < n; ++i) {
            scanf("%d", &t);
            ++cnt[t];
        }
        int flag = 0;
        for (int i = 0; i < 100; ++i)
            while (cnt[i] > 0) {
                if (flag)
                    printf(" ");
                flag = 1;
                printf("%d", i);
                --cnt[i];
            }
        printf("\n");
        memset(cnt, 0, sizeof(cnt));
    }
    return 0;
}