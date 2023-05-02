#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct cmp {
    bool operator() (const int& a, const int& b) {
        return a > b;
    }
};

int main() {
    //freopen("input.txt", "r", stdin);
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    
    string s = "";
    while (cin >> s) {
        priority_queue<int, vector<int>, cmp> pq;
        int n = s.length();
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += s[i] - '0';
        if (sum % n != 0) {
            cout << s << ": invalid # of balls\n";
            continue;
        }

        int flag = true;

        for (int i = 1; i < 10 * n; ++i) {
            if (s[i % n] != '0') {
                int cnt = 0;
                while (!pq.empty() && pq.top() == i) {
                    ++cnt;
                    pq.pop();
                }
                if (cnt > 1) {
                    flag = false;
                    break;
                }
                pq.push(s[i % n] - '0' + i);
            }
            else {
                if (!pq.empty() && pq.top() == i) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) 
            cout << s << ": Valid with " << sum / n << " balls\n";
        else
            cout << s << ": Invalid pattern\n";
    }  
    return 0;
}