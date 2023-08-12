#include <bits/stdc++.h>

using namespace std;

vector<int> preorder;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int x) {
		data = x;
		left = nullptr;
		right = nullptr;
	}
};

Node* solve(int lo, int hi) {
	if (lo > hi) return nullptr;
	Node* root = new Node(preorder[lo]);
	int i;
	for (i = lo; i <= hi; ++i)
		if (preorder[i] > root->data)
			break;
	root->left = solve(lo + 1, i - 1);
	root->right = solve(i, hi);
	return root;
}

void postorder(Node* root) {
	if (root == nullptr) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << endl;
}

int main() {
	int t;
	while (cin >> t)
		preorder.push_back(t);
	Node* root = solve(0, int(preorder.size() - 1));
	postorder(root);
	return 0;
}