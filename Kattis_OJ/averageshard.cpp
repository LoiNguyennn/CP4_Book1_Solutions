#include <iostream>
#include <vector>

using namespace std;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int c, e;
        cin >> c >> e;
        double ave_cs = 0, ave_e = 0;
        vector<int> cs_iq;
        cs_iq.reserve(c);
        for (int i = 0; i < c; ++i) {
            int iq;
            cin >> iq;
            ave_cs += iq;
            cs_iq.push_back(iq);
        }

        for (int i = 0; i < e; ++i) {
            int iq;
            cin >> iq;
            ave_e += iq;
        }

        ave_cs /= c;
        ave_e /= e;

        int ans = 0;
        for (int x : cs_iq) {
            if (x < ave_cs && x > ave_e)
                ++ans;
        }

        cout << ans << endl;
    }
    return 0;
}