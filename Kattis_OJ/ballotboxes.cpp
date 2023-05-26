#include <bits/stdc++.h>

using namespace std;

struct City {
	double ratio;
	int boxes, popu;
};

bool operator < (const City& a, const City& b) {
	return a.ratio < b.ratio;
}

int main() {	
	freopen("input.txt", "r", stdin);
	int N, B;
	while (cin >> N >> B) {
		if (N == -1 && B == -1)
			break;
		priority_queue<City> pq;
		for (int i = 0; i < N; ++i) {
			int a;
			cin >> a;
			City t;
			t.ratio = double(a);
			t.popu = a;
			t.boxes = 1;
			pq.push(t);
		}
		B -= N;
		while (B--) {
			City t = pq.top();
			pq.pop();
			++t.boxes;
			t.ratio = (double(t.popu) / t.boxes);
			pq.push(t);
		}
		cout << ceil(pq.top().ratio) << endl;
	}
	return 0;
}