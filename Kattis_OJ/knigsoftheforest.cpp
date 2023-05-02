#include <bits/stdc++.h>

#define MOD 1000000007
#define INF 1000000000

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct cmp {
    bool operator() (const pair<int, ull>& a, const pair<int, ull>& b) {
        return a.second < b.second;
    }
};

bool cmp2 (pair<int, ull> a, pair<int, ull> b) {
    return a.first < b.first;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq; // pool
    
    int k, n;
    cin >> k >> n;
    int karl_entry;
    ull karl_str;
    cin >> karl_entry >> karl_str;
 
    vector<pair<int, ull>> v;
    v.reserve(n + k - 1);
    v.push_back({karl_entry, karl_str});
 
    for (int i = 1; i <= n + k - 2; ++i) {
        int t1;
        ull t2;
        cin >> t1 >> t2;
        v.push_back({t1, t2});
    }

    sort(v.begin(), v.end(), cmp2);

    int valid = false;
    int cnt = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i].first == 2011)
            pq.push({v[i].first, v[i].second});
        else {
            if (pq.top().first == karl_entry && pq.top().second == karl_str) {
                valid = true;
                break;
            }
            pq.pop();
            pq.push({v[i].first, v[i].second});
            ++cnt;
        }
    }

    if (pq.top().first == karl_entry && pq.top().second == karl_str)
        valid = true;

    if (valid) 
        cout << 2011 + cnt << endl;
    else 
        cout << "unknown\n";
    return 0;
}