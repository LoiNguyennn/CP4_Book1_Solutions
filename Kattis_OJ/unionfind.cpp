#include <bits/stdc++.h>

using namespace std;

int p[1000001], r[1000001];

int find_set(int i) {
	if (p[i] == i) return i;
	return p[i] = find_set(p[i]);
}

void union_set(int i, int j) {
	int x = find_set(i), y = find_set(j);
	if (x == y) 
		return;
	if (r[x] > r[y]) 
		swap(x, y);
	p[x] = y;
	if (r[x] == r[y])
		++r[y];
}

bool isSameSet(int i, int j) {
	return (find_set(i) == find_set(j));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N, Q;
	cin >> N >> Q;
	for (int i = 0; i < N; ++i) {
		p[i] = i;
	}
	while (Q--) {
		char c;
		cin >> c;
		int a, b;
		cin >> a >> b;
		if (c == '?') {
			if (isSameSet(a, b)) cout << "yes\n";
			else cout << "no\n";
		} else {
			union_set(a, b);
		}
	}
	return 0;
}