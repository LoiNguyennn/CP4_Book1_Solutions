#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve1(ll a[], int n) {
    for (int i = 0; i < n; ++i) {
        if (binary_search(a, a + n, 7777 - a[i])) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

void solve2(ll a[], int n) {
    for (int i = 0; i < n - 1; ++i) 
        if (a[i] == a[i + 1]) {
            cout << "Contains duplicate\n";
            return;
        }
    cout << "Unique\n";
}

void solve3(ll a[], int n) {
    int l = 0;
    while (l < n) {
        int i = l;
        while (i < n && a[i] == a[l]) ++i;
        if ((i - l) > (n / 2)) {
            cout << a[l] << endl;
            return;
        }
        l = i;
    }
    cout << "-1\n";
}

void solve4(ll a[], int n) {
    if (n % 2 == 0) {
        cout << a[n / 2 - 1] << " " << a[n / 2] << endl;
    } else {
        cout << a[n / 2] << endl;
    }
}

void solve5(ll a[], int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i] >= 100 && a[i] <= 999) cout << a[i] << " ";
    }
}

int main() {
    int n, t;
    cin >> n >> t;
    ll a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    if (t == 1) {
 
        solve1(a, n);
    } else if (t == 2) {
        sort(a, a + n);
        solve2(a, n);
    } else if (t == 3) {
       
        solve3(a, n);
    } else if (t == 4) {
    
        solve4(a, n);
    } else {
       
        solve5(a, n);
    }
    return 0;
}