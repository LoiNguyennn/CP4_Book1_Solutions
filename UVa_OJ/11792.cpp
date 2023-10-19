#include <bits/stdc++.h>

using namespace std;

int cnt[10000], dist[10000];
int n, s;

int bfs(int start, vector<vector<int>>& AL) {
    for (int i = 0; i < n; ++i) dist[i] = -1;
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : AL[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] > 1)
            ans += dist[i];
    }
    return ans;
}

int main() {
    int TC;
    cin >> TC;
    while (TC--) {
        cin >> n >> s;
        vector<vector<int>> AL(n);
        for (int i = 0; i < n; ++i) cnt[i] = 0;

        for (int i = 0; i < s; ++i) {
            int prev, next;
            cin >> prev;
            --prev;
            ++cnt[prev];
            while (cin >> next && next) {
                --next;
                ++cnt[next];
                AL[prev].push_back(next);
                AL[next].push_back(prev);
                prev = next;
            }
        }    

        int min_cost = INT_MAX, location;
        for (int i = 0; i < n; ++i) {
            if (cnt[i] > 1) {
                int res = bfs(i, AL);
                if (res < min_cost) {
                    min_cost = res;
                    location = i + 1;
                }
            }
        }

        cout << "Krochanska is in: " << location << endl;
    }
    return 0;
}