#include <bits/stdc++.h>

using namespace std;

struct Rep {
    string name;
    int cost = 0;
};

bool operator < (const Rep& a, const Rep& b) {
    if (a.cost == b.cost)
        return a.name < b.name;
    if (a.cost < b.cost)
        return true;
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string title;
        cin.ignore();
        getline(cin, title);
        int m, n, b;
        cin >> m >> n >> b;
        map<string, int> ingredients;
        for (int i = 0; i < m; ++i) {
            string s;
            int c;
            cin >> s >> c;
            ingredients.insert({s, c});
        }
        vector<Rep> v;
        v.reserve(n);
        for (int i = 0; i < n; ++i) {
            Rep a;
            cin.ignore();
            getline(cin, a.name);
            int k;
            cin >> k;
            for (int j = 0; j < k; ++j) {
                string name;
                cin >> name;
                int num;
                cin >> num;
                a.cost += ingredients[name] * num;
            }
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < title.length(); ++i) {
            if (title[i] >= 'a' && title[i] <= 'z')
                title[i] -= 32;
        }
        cout << title << endl;
        bool flag = false;
        for (int i = 0; i < v.size(); ++i) {
            if (v[i].cost <= b) {
                flag = true;
                cout << v[i].name << endl;        
            }
        }
        if (!flag)
            cout << "Too expensive!\n";
        cout << '\n';
    }
    return 0;
}