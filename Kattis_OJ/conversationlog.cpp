#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000000
#define INP() freopen("input.txt", "r", stdin)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second > b.second) return true;
    else if (a.second == b.second)
        return a.first < b.first;
    return false;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    
    int n;
    cin >> n;
    cin.ignore();
    unordered_map<string, unordered_set<string>> mp;
    unordered_map<string, int> word;
    for (int i = 0; i < n; ++i) {
        string str;
        getline(cin, str);
        stringstream ss(str);
        string name;
        ss >> name;
        string tmp;
        while (ss >> tmp) {
            mp[name].insert(tmp);
            word[tmp]++;
        }
    }
    
    vector<pair<string, int>> v;
    for (auto x : word) {
        int flag = false;
        for (auto y : mp) {
            if (y.second.find(x.first) == y.second.end()) {
                flag = true;
                break;
            }
        }
        if (!flag)
            v.push_back({x.first, x.second});
    }
    if (v.size()) {
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); ++i)
            cout << v[i].first << endl;
    } else {
        cout << "ALL CLEAR\n";
    }
    return 0;
}