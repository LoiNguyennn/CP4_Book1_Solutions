#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <iomanip>

using namespace std;

struct Anten {
    int x, y, r;
};

typedef pair<double, int> ii;

double calc(Anten& a, Anten& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    double d = sqrt(dx * dx + dy * dy);
    if (d > a.r + b.r)
        return d - a.r - b.r;
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<Anten> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y >> a[i].r;

    vector<vector<ii>> AL(n);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double w = calc(a[i], a[j]);
            AL[i].emplace_back(w, j);
            AL[j].emplace_back(w, i);
        }
    }

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    vector<bool> taken(n, false);
    taken[0] = true;
    for (ii x : AL[0])
        pq.emplace(x.first, x.second);
    
    double ans = 0;
    int num_taken = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        double w = pq.top().first;
        pq.pop();
        if (taken[u]) 
            continue;
        taken[u] = true;
        ans += w;
        for (ii x : AL[u]) 
            pq.emplace(x.first, x.second);
        ++num_taken;
        if (num_taken == n - 1) break;
    }

    cout << fixed << setprecision(8) << ans << endl;
    return 0;
}