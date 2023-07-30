#include <iostream>
#include <vector>
#include <queue>

#define inf 1e9

using namespace std;

typedef pair<int, int> ii;

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        int n, m;
        cin >> n >> m;
        vector<vector<ii>> AL(n);

        int total_cost = 0;
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            --u; --v;
            total_cost += w;
            AL[u].emplace_back(w, v);
            AL[v].emplace_back(w, u);
        }

        bool visited[n];
        for (int i = 0; i < n; ++i)
            visited[i] = false;


        int num_taken = 0, mst_cost = 0;
        priority_queue<ii> pq;
       
        visited[0] = true;
        for (auto x : AL[0])
            pq.emplace(x.first, x.second);
        

        while (!pq.empty()) {
            int u = pq.top().second, w = pq.top().first;
            pq.pop();
            if (visited[u]) continue;

            mst_cost += w;
            visited[u] = true;

            for (auto x : AL[u]) 
                if (!visited[x.second])
                    pq.emplace(x.first, x.second);

            ++num_taken;
            if (num_taken == n - 1) break;
        }

        cout << total_cost - mst_cost << endl;
    }
    cin >> TC;
    return 0;
}