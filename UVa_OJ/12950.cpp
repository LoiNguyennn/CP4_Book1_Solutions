#include <bits/stdc++.h>

#define inf 1e9

using namespace std;

typedef pair<int, int> ii;

int main() {
    int c, v;
    while (cin >> c >> v) {
        vector<vector<ii>> AL(c);    
        for (int i = 0; i < v; ++i) {
            int c1, c2, g;
            cin >> c1 >> c2 >> g;
            --c1; --c2;
            AL[c1].emplace_back(g, c2);
            AL[c2].emplace_back(g, c1);
        }    

        vector<int> dist(c, inf);
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        dist[0] = 0;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            int d = pq.top().first, u = pq.top().second;
            pq.pop();
            if (d > dist[u]) continue;
            for (auto x : AL[u]) {
                int w1 = x.first, v = x.second;
                for (auto y : AL[v]) {
                    int w2 = y.first, a = y.second;
                    if (dist[u] + w1 + w2 < dist[a]) {
                        dist[a] = dist[u] + w1 + w2;
                        pq.emplace(dist[a], a);
                    }
                }
            }
        }

        if (dist[c - 1] == inf)
            cout << "-1\n";
        else
            cout << dist[c - 1] << endl;
    }
    return 0;
}