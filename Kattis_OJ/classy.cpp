#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct Person {
    string name;
    vector<string> clss;
};

int compareClass(string a, string b) {
    // 1 if a > b, 0 if a == b, -1 if a < b
    if (a == "upper")
        return !(b == "upper");
    if (b == "upper")
        return -1;
    if (a == "middle") 
        return !(b == "middle");
    if (b == "middle")
        return -1;
    return 0;
}

bool cmp(const Person& a, const Person& b) {
    int i = a.clss.size() - 1;
    int j = b.clss.size() - 1;
    while (i >= 0 && j >= 0) {
        int flag = compareClass(a.clss[i], b.clss[j]);
        if (flag == 1) return true;
        if (flag == -1) return false;
        --i;
        --j;
    }
    while (i >= 0) {
        if (a.clss[i] == "lower") return false;
        if (a.clss[i] == "upper") return true;
        --i;
    }

    while (j >= 0) {
        if (b.clss[j] == "lower") return true;
        if (b.clss[j] == "upper") return false;
        --j;
    }
    return (a.name < b.name);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt", "r", stdin);
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        if (n > 0) {
            Person a[n];
            for (int i = 0; i < n; ++i) {
                cin >> a[i].name; a[i].name.pop_back();
                string s;
                cin >> s;

                string tmp;
                for (int j = 0; j < s.length(); ++j) {
                    if (s[j] != '-') 
                        tmp += s[j];
                    else {
                        a[i].clss.push_back(tmp);
                        tmp.clear();
                    }
                }
                a[i].clss.push_back(tmp);
                cin >> s; // garbage
            }
            sort(a, a + n, cmp);

            for (int i = 0; i < n; ++i) {
                cout << a[i].name << endl;
            }
        }
        for (int i = 0; i < 30; ++i)
            cout << "=";
        cout << endl;
    }
    return 0;
}
