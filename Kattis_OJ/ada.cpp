#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> s(n);
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    vector<vector<ll>> sequences;
    sequences.push_back(s);
    ll last = 0;
    ll cnt = 0;
    while (true) {
        vector<ll> v;
        for (int i = 0; i < sequences[last].size() - 1; ++i)
            v.push_back(sequences[last][i] - sequences[last][i + 1]);
        sequences.push_back(v);
        ++last;
        ++cnt;
        bool flag = true;
        for (int i = 0; i < v.size() - 1; ++i)
            if (v[i] != v[i + 1]) {
                flag = false;
                break;
            }
        if (flag) {
            ll diff = v[0];
            for (int i = last - 1; i >= 0; --i) {
                ll id = sequences[i].size() - 1;
                diff = sequences[i][id] - diff;
            }
            cout << cnt << " " << diff << endl;
            break;
        }
    }
    return 0;
}