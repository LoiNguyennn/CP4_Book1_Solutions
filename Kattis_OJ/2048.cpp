#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void left(int a[][4]) {
    for (int i = 0; i < 4; ++i) {
        vector<int> v;
        for (int j = 0; j < 4; ++j)
            if (a[i][j] != 0)
                v.push_back(a[i][j]);
        if (v.size() == 0)
            continue;
        for (int j = 0; j < v.size() - 1; ++j) {
            if (v[j] == v[j + 1]) {
                v[j] <<= 1;
                v[j + 1] = 0;
            }
        }
        int idx = 0;
        for (int j = 0; j < v.size(); ++j)
            if (v[j]) a[i][idx++] = v[j];
        while (idx < 4)
            a[i][idx++] = 0;
    }
}

void right(int a[][4]) {
    for (int i = 0; i < 4; ++i) {
        vector<int> v;
        for (int j = 0; j < 4; ++j)
            if (a[i][j] != 0)
                v.push_back(a[i][j]);
        if (v.size() == 0)
            continue;
        for (int j = v.size() - 1; j >= 1; --j) {
            if (v[j] == v[j - 1]) {
                v[j] <<= 1;
                v[j - 1] = 0;
            }
        }
        int idx = 3;
        for (int j = v.size() - 1; j >= 0; --j)
            if (v[j]) a[i][idx--] = v[j];
        while (idx >= 0)
            a[i][idx--] = 0;
    }
}

void up(int a[][4]) {
    for (int i = 0; i < 4; ++i) {   
        vector<int> v;
        for (int j = 0; j < 4; ++j)
            if (a[j][i] != 0)
                v.push_back(a[j][i]);
        if (v.size() == 0)
            continue;
        for (int j = 0; j < v.size() - 1; ++j) {
            if (v[j] == v[j + 1]) {
                v[j] <<= 1;
                v[j + 1] = 0;
            }
        }
        int idx = 0;
        for (int j = 0; j < v.size(); ++j)
            if (v[j]) a[idx++][i] = v[j];
        while (idx < 4)
            a[idx++][i] = 0;
    }
}

void down(int a[][4]) {
    for (int i = 0; i < 4; ++i) {   
        vector<int> v;
        for (int j = 0; j < 4; ++j)
            if (a[j][i] != 0)
                v.push_back(a[j][i]);
        if (v.size() == 0)
            continue;
        for (int j = v.size() - 1; j > 0; --j) {
            if (v[j] == v[j - 1]) {
                v[j] <<= 1;
                v[j - 1] = 0;
            }
        }
        int idx = 3;
        for (int j = v.size() - 1; j >= 0; --j)
            if (v[j]) a[idx--][i] = v[j];
        while (idx >= 0)
            a[idx--][i] = 0;
    } 
}

int main() {
    int a[4][4];
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) 
            cin >> a[i][j];
    int n;
    cin >> n;
    if (n == 0)
        left(a);
    else if (n == 2)
        right(a);
    else if (n == 1)
        up(a);
    else 
        down(a);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}