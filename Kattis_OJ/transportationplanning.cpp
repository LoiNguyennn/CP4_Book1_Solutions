#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <iomanip>

#define inf 1e9
#define eps -1e7

using namespace std;

double AM[100][100], AM_t[100][100];

double getDist(pair<int, int> a, pair<int, int> b) {
	int dx = a.first - b.first;
	int dy = a.second - b.second;
	return sqrt(dx * dx + dy * dy);
}

void cop(int n) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			AM_t[i][j] = AM[i][j];
}

int main() {
	int n;
	while (cin >> n && n) {
		
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				AM[i][j] = inf;
				if (i == j)
					AM[i][j] = 0;
			}
		}


		vector<pair<int, int>> loc(n);
		for (int i = 0; i < n; ++i)
			cin >> loc[i].first >> loc[i].second;

		int m;		
		cin >> m;

		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			AM[u][v] = AM[v][u] = getDist(loc[u], loc[v]);
		}

	
		cop(n);

		for (int k = 0; k < n; ++k) 
			for (int i = 0; i < n; ++i) 
				for (int j = 0; j < n; ++j)
					AM_t[i][j] = min(AM_t[i][j], AM_t[i][k] + AM_t[k][j]);

		double time = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (AM_t[i][j] != inf)
					time += AM_t[i][j];
			}
		}

		double min_time = INT_MAX;
		int x, y;
		for (int u = 0; u < n; ++u) {
			for (int v = u + 1; v < n; ++v) {
				if (AM[u][v] == inf) {
					cop(n);
					AM_t[u][v] = AM_t[v][u] = getDist(loc[u], loc[v]);
					for (int k = 0; k < n; ++k) 
						for (int i = 0; i < n; ++i) 
							for (int j = 0; j < n; ++j)
								AM_t[i][j] = min(AM_t[i][j], AM_t[i][k] + AM_t[k][j]);

					double sum = 0;
					for (int i = 0; i < n; ++i) 
						for (int j = i + 1; j < n; ++j)
							if (AM_t[i][j] != inf)
								sum += AM_t[i][j];

					if (sum < min_time) {
						min_time = sum;
						x = u;
						y = v;
					}
				}
			}
		}

		if (min_time < time) {
			cout << "adding " << x << " " << y << " reduces " << fixed << setprecision(10) << time << " to " << min_time << endl;
		} else {
			cout << fixed << setprecision(10) << "no addition reduces " << time << endl;
		}
	}
	return 0;
}