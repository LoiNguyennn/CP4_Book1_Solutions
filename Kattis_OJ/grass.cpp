#include <bits/stdc++.h>

#define EPS 1e-9

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	double n, l, w;
	while (cin >> n >> l >> w) {
		vector<pair<double, double>> segment;
        for (int i = 0; i < n; i++) {
            double c, r;
            cin >> c >> r;
            double x = r * r - (w / 2.0) * (w / 2.0);
            if (x < 0) continue;  // Useless sprinkler
            segment.push_back(make_pair(c - sqrt(x), c + sqrt(x)));
        }

		sort(segment.begin(), segment.end());
       
        bool possible = true;
        double covered = 0;
        int ans = 0;

        n = segment.size();

        for (int i = 0; i < n; i++) {
            if (covered + EPS > l) break;
            if (segment[i].second < covered + EPS) continue; 
            if (segment[i].first > covered + EPS) {
                possible = false;
                break;
            }
            double max_r = -1.0;
            int max_id = i;
            for (int j = i; j < n && (segment[j].first < covered + EPS); j++) {
                if (segment[j].second > max_r) {
                    max_r = segment[j].second;
                    max_id = j;
                }
            }
            ans++;
            covered = max_r;
            i = max_id;
        }
        if (!possible || covered < l)
            cout << -1 << endl;
        else
            cout << ans << endl;
	}
	return 0;
}