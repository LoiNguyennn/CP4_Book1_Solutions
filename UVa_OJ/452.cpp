#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

#define inf 1e9

using namespace std;

typedef pair<int, int> ii;

int cost[26], dist[26];

int main() {
	int TC;
	cin >> TC;
	cin.ignore();
	string in;	
	getline(cin, in);
	while (TC--) {
		vector<vector<int>> AL(26); 
		int in_deg[26] = {0};
		for (int i = 0; i < 26; ++i) {
			dist[i] = inf;
			cost[i] = 0;
		}

		while (getline(cin, in) && in != "") {
			stringstream sin(in);
			char v;
			string s;
			int w;
			sin >> v >> w;

			cost[v - 'A'] = -w;
			sin >> s;
			for (char u : s)
				AL[u - 'A'].push_back(v - 'A');
		}


		priority_queue<ii, vector<ii>, greater<ii>> pq;
		for (int i = 0; i < 26; ++i)
			if (in_deg[i] == 0) {
				pq.emplace(cost[i], i);
				dist[i] = cost[i];
			}	

		while (!pq.empty()) {
			int u = pq.top().second, d = pq.top().first;
			pq.pop();
			if (d > dist[u]) continue;

			for (int v : AL[u]) {
				if (dist[u] + cost[v] < dist[v]) {
					dist[v] = dist[u] + cost[v];
					pq.emplace(dist[v], v);
				}
			}
		}

		
		int ans = inf;
		for (int i = 0; i < 26; ++i)
			ans = min(ans, dist[i]);
		cout << -ans << endl;
		if (TC) cout << endl;
	}
	return 0;
}