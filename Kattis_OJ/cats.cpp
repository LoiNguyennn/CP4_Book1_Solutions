#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

priority_queue<ii, vector<ii>, greater<ii>> pq;
bool taken[2000];

void process(int u, vector<vector<ii>>& AL) {
    taken[u] = true;
    for (auto v : AL[u]) {
        if (!taken[v.first])
            pq.emplace(v.second, v.first);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int TC;
    cin >> TC;
    while (TC--) {
        int M, C;
        cin >> M >> C;
        while (!pq.empty()) pq.pop();
        for (int i = 0; i < C; ++i) taken[i] = false;

        vector<vector<ii>> AL(C);
        for (int i = 0; i < C * (C - 1) / 2; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            AL[u].emplace_back(v, w);
            AL[v].emplace_back(u, w);
        }

        int mst_cost = 0, num_taken = 0;
        process(0, AL);

        while (!pq.empty()) {
            int w = pq.top().first, u = pq.top().second;
            pq.pop();
            if (taken[u]) continue;
            mst_cost += w;
            ++num_taken;
            process(u, AL);
            if (num_taken == C - 1) break;
        }
        if (M >= mst_cost + C) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
    return 0;
}