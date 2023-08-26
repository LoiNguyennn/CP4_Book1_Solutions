#include <iostream>
#include <cmath>
#include <vector>

#define EPS 1e-6

using namespace std;

vector<bool> visited;
vector<int> match;

double getDist(pair<double, double>& a, pair<double, double>& b) {
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

bool AugmentingPath(vector<vector<int>>& AL, int L) {
    if (visited[L]) return false;
    visited[L] = true;
    for (int R : AL[L]) {
        if (match[R] == -1 || AugmentingPath(AL, match[R])) {
            match[R] = L;
            return true;
        }
    }
    return false;
}

int main() {
    int m, n;
    int tc = 1;
    while (cin >> m && m) {
        vector<pair<double, double>> robots;
        vector<pair<double, double>> holes;
        for (int i = 0; i < m; ++i) {
            double x, y;
            cin >> x >> y;
            robots.emplace_back(x, y);
        }

        cin >> n;
        for (int i = 0; i < n; ++i) {
            double x, y;
            cin >> x >> y;
            holes.emplace_back(x, y);
        }

        vector<vector<int>> AL_5s(m), AL_10s(m), AL_20s(m);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                double dist = getDist(robots[i], holes[j]);
                if (dist < 50 || fabs(dist - 50) < EPS) 
                    AL_5s[i].push_back(j);
                if (dist < 100 || fabs(dist - 100) < EPS)
                    AL_10s[i].push_back(j);
                if (dist < 200 || fabs(dist - 200) < EPS)
                    AL_20s[i].push_back(j);
            }
        }

        int MCBM1 = 0;
        match.assign(n, -1);
        for (int i = 0; i < m; ++i) {
            visited.assign(m, false);
            MCBM1 += AugmentingPath(AL_5s, i);
        }

        int MCBM2 = 0;
        match.assign(n, -1);
        for (int i = 0; i < m; ++i) {
            visited.assign(m, false);
            MCBM2 += AugmentingPath(AL_10s, i);
        }

        int MCBM3 = 0;
        match.assign(n, -1);
        for (int i = 0; i < m; ++i) {
            visited.assign(m, false);
            MCBM3 += AugmentingPath(AL_20s, i);
        }

        cout << "Scenario " << tc++ << endl;
        cout << "In 5 seconds " << MCBM1 << " robot(s) can escape\n";
        cout << "In 10 seconds " << MCBM2 << " robot(s) can escape\n";
        cout << "In 20 seconds " << MCBM3 << " robot(s) can escape\n";
        cout << endl;
    }
    return 0;
}