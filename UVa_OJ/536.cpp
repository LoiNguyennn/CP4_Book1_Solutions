#include <iostream>

using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;
    Node (char x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

string preorder, inorder;
int root_id;

Node* construct(int lo, int hi) {
    if (lo > hi)
        return nullptr;
    char root = preorder[root_id++];
    int id;
    for (int i = lo; i <= hi; ++i) {
        if (inorder[i] == root)
            id = i;
    }
    Node* res = new Node(root);
    res->left = construct(lo, id - 1);
    res->right = construct(id + 1, hi);
    return res;
}

void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

int main() {
    while (cin >> preorder >> inorder) {
        root_id = 0;
        int n = preorder.size();
        Node* res = construct(0, n - 1);
        postorder(res);
        cout << endl;
    }
    return 0;
}