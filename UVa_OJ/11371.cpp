#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    string n;
    while (cin >> n) {
        string a = n;
        string b = n;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end(), greater<char>());

        if (a[0] == '0') {
            for (int i = 0; i < a.size(); ++i)
                if (a[i] != '0') {
                    swap(a[i], a[0]);
                    break;
                }
        }

        ll aa = stoll(a);
        ll bb = stoll(b);
        cout << bb << " - " << aa << " = " << bb - aa << " = 9 * " << (bb - aa) / 9 << endl;

    }
    return 0;
}