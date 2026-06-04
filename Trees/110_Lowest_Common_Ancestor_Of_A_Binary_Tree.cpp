/* Given a binary tree, find the lowest common ancestor (LCA) of two given nodes p and q.

LCA = The lowest node in the tree that has both p and q as descendants. A node can be a desendant of itself.

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
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

class Solution {
public: 
    Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        if(root == NULL || root == p || root == q) {
            return root;
        }

        Node* left = lowestCommonAncestor(root->left, p, q);
        Node* right = lowestCommonAncestor(root->right, p, q);

        if(left == NULL) {
            return right;
        }
        else if(right == NULL) {
            return left;
        }
        else {
            return root;
        }
    }
};

int main() {
    vector<int> preorder = {3,5,6,-1,-1,2,7,-1,-1,4,-1,-1,1,0,-1,-1,8,-1,-1};
    Node* root = buildTree(preorder);

    Node* p = root->left; // 5
    Node* q = root->right; // 1

    Solution sol;
    Node* lca = sol.lowestCommonAncestor(root, p, q);
    cout << "LCA of " << p->data << " and " << q->data << " is: " << lca->data << endl;

    return 0;
}