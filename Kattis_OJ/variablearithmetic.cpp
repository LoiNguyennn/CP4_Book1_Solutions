#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    unordered_map<string, int> mp;
    string in;
    while (getline(cin, in) && in != "0") {
        stringstream sin(in);
        string first, second;
        sin >> first >> second;
        if (second == "=") {
            int t;
            sin >> t;
            mp[first] = t;
        } else {
            vector<string> v;
            v.push_back(first);
            string tmp;
            while (sin >> tmp) {
                v.push_back(tmp);
                sin >> tmp;
            }
            int number = 0;
            vector<string> ans;
            for (int i = 0; i < v.size(); ++i) {
                if (v[i][0] >= '0' && v[i][0] <= '9') {
                    number += stoi(v[i]);
                }
                else if (mp.find(v[i]) != mp.end())
                    number += mp[v[i]];
                else ans.push_back(v[i]);
            }
            if (number) {
                cout << number;
                for (int i = 0; i < ans.size(); ++i)
                    cout << " + " << ans[i];
                cout << endl;
            } else {
                for (int i = 0; i < ans.size() - 1; ++i)
                    cout << ans[i] << " + ";
                cout << ans[ans.size() - 1] << endl;
            }
        }
    }
    return 0;
}