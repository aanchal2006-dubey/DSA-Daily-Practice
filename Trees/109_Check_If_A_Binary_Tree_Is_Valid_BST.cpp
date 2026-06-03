/* Given the root of a binary tree, determine if it is a valid Binary Search Tree.  A valid BST follows:  
    Left subtree of a node contains only nodes with val < node->val  
    Right subtree of a node contains only nodes with val > node->val  
    Both left and right subtrees must also be BSTs

Input: root = [2,1,3]
Output: true

Input: root = [5,1,4,null,null,3,6]
Output: false
*/

#include<iostream>
#include<vector>
#include<climits>
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

class Solution {
public:
    bool validate(Node* root, long long min, long long max) {
        if(root == NULL) {
            return true;
        }

        if(root->data <= min || root->data >= max) {
            return false;
        }

        return validate(root->left, min, root->data) && validate(root->right, root->data, max);
    }

    bool isValidBST(Node* root) {
        return validate(root, LLONG_MIN, LLONG_MAX);
    }
};

int main() {
    vector<int> preorder = {2, 1, -1, -1, 3, -1, -1};
    Node* root = buildTree(preorder);

    Solution sol;

    if(sol.isValidBST(root)) {
        cout << "The binary tree is a valid BST." << endl;
    } else {
        cout << "The binary tree is not a valid BST." << endl;
    }

    return 0;
}