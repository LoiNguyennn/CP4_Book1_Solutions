#include <bits/stdc++.h>

using namespace std;

struct UnionFind {
	int p[30001], size[30001];
	UnionFind (int n) {
		for (int i = 0; i < n; ++i) {
			p[i] = i;
			size[i] = 1;
		}
	}
	int find_set(int i);
	void union_set(int i, int j);
};

int UnionFind::find_set(int i) {
	if (p[i] == i) return i;
	return p[i] = find_set(p[i]);
}

void UnionFind::union_set(int i, int j) {
	int x = find_set(i), y = find_set(j);
	if (x == y) return;
	if (size[x] > size[y])
		swap(x, y);
	p[x] = y;
	size[y] += size[x];
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		if (n == 0 && m == 0) break;
		UnionFind UF(n);
		for (int i = 0; i < m; ++i) {
			int k;
			cin >> k;
			int students[k];
			for (int j = 0; j < k; ++j)
				cin >> students[j];
			for (int j = 0; j < k - 1; ++j)
				UF.union_set(students[j], students[j + 1]);
		}
		int parentOfZero = UF.find_set(0);
		cout << UF.size[parentOfZero] << endl;
	}
	return 0;
}