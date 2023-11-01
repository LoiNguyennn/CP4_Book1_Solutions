#include <bits/stdc++.h>

using namespace std;

int main() {
    string n;
    while (cin >> n && n != "0") {
        int even_idx = 0, odd_idx = 0;
        for (int i = 0; i < n.size(); i += 2)
            even_idx += n[i] - '0';
        for (int i = 1; i < n.size(); i += 2)
            odd_idx += n[i] - '0';

        if ((even_idx - odd_idx) % 11 == 0)
            cout << n << " is a multiple of 11.\n";
        else
            cout << n << " is not a multiple of 11.\n";
    }

    return 0;
}