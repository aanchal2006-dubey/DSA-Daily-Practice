/* Kth Level of a Tree.

Input: root = [1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1], k = 3
Output: [7, 4, 5]
*/

#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;
Node* buildTree(vector<int>& preorder) {
    idx++;

    if(preorder[idx] == -1) {
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;
}

void kthLevel(Node* root, int k, vector<int>& ans) {
    if(root == NULL) {
        return;
    }

    if(k == 1) {
        ans.push_back(root->data);
        return;
    }

    kthLevel(root->left, k - 1, ans);
    kthLevel(root->right, k - 1, ans);
}

int main() {
    vector<int> preorder = {1, 2, 7, -1, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);
    int k = 3;
    vector<int> ans;
    kthLevel(root, k, ans);

    for(int i : ans) {
        cout << i << " ";
    }
}