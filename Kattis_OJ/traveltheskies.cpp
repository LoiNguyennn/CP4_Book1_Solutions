#include <bits/stdc++.h>

using namespace std;

struct flight {
    int start;
    int dest;
    int day;
    int cap;
};

bool solve() {
    int k, n, m;
    cin >> k >> n >> m;

    unordered_map<int, vector<flight>> flights; // day, the flights of this day 
    unordered_map<int, vector<pair<int, int>>> incomingPP; // day, airport, number of customers
    vector<int> airport(k + 1, 0); // number of custemers waiting at airport i (1 <= i <= k)

    // push each flight into hash map
    for (int i = 0; i < m; ++i) {
        flight tmp;
        cin >> tmp.start >> tmp.dest >> tmp.day >> tmp.cap;
        flights[tmp.day].push_back(tmp);
    }

    // make a hash set of incoming people
    for (int i = 0; i < k * n; ++i) {
        int a, d, c;
        cin >> a >> d >> c;
        incomingPP[d].push_back({a, c});
    }

    // process from day 1 to n
    for (int i = 1; i <= n; ++i) {
        for (pair<int, int> x : incomingPP[i]) {
            airport[x.first] += x.second;
        }
        for (flight x : flights[i]) {
            airport[x.start] -= x.cap;
            if (airport[x.start] < 0) return false;
        }

        // this loop cannot be nested in the loop above because these customer must be arrived on i + 1 day
        for (flight x : flights[i]) {
            airport[x.dest] += x.cap;
        }
    }
    return true;
}

int main() {
    if (solve()) cout << "optimal\n";
    else cout << "suboptimal\n";
    return 0;
}