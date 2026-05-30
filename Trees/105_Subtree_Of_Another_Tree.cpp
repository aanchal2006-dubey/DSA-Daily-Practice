/* Given the roots of two binary trees and subRoot, return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree is a tree that consists of a node in tree and all of this node's descendants. The tree could also be considered as a subtree of itself. 

Input: root = [3,4,5,1,2], subRoot = [4,1,2]
Output: true

Input: root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
Output: false
*/

#include<iostream>
#include<vector>
#include <queue>
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

Node* buildTreeLevelOrder(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return NULL;

    Node* root = new Node(nodes[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        Node* curr = q.front();
        q.pop();

        // Handle left child
        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new Node(nodes[i]);
            q.push(curr->left);
        }
        i++;

        // Handle right child
        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new Node(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

class Solution {
public:
    bool isSameTree(Node* p, Node* q) {
        if(p == NULL || q == NULL) {
            return p == q;
        }

        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);

        return isLeftSame && isRightSame && (p->data == q->data);   
    }

    bool isSubtree(Node* root, Node* subRoot) {
        if(root == NULL) {
            return false;
        }

        if(isSameTree(root, subRoot)) {
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};

int main() {
    int n;
    cout<<"Enter the number of nodes for tree 1: ";
    cin>>n;

    vector<int> nodes1(n);
    cout<<"Enter the nodes for tree 1 (use -1 for NULL): ";
    for(int i = 0; i < n; i++) {
        cin>>nodes1[i];
    }

    int idx1 = 0;
    Node* root1 = buildTreeLevelOrder(nodes1);

    cout<<"Enter the number of nodes for tree 2: ";
    cin>>n;

    vector<int> nodes2(n);
    cout<<"Enter the nodes for tree 2 (use -1 for NULL): ";
    for(int i = 0; i < n; i++) {
        cin>>nodes2[i];
    }

    int idx2 = 0;
    Node* root2 = buildTreeLevelOrder(nodes2);

    Solution sol;
    bool result = sol.isSubtree(root1, root2);
    cout<<"Is tree 2 a subtree of tree 1? "<<(result ? "Yes" : "No")<<endl;

    return 0;
}