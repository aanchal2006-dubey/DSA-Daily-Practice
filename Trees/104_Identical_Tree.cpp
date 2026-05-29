/* Given the root of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Input: p = [1,2,3], q = [1,2,3]
Output: true

Input: p = [1,2], q = [1,null,2]
Output: false

Input: p = [1,2,1], q = [1,1,2]
Output: false
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

Node* buildTree(const vector<int>&nodes, int& idx) {
    if (idx >= nodes.size() || nodes[idx] == -1) {
        idx++;
        return NULL;
    }

    Node* root = new Node(nodes[idx++]);
    root->left = buildTree(nodes, idx);
    root->right = buildTree(nodes, idx);

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
};

int main() {
    int n;
    cout<<"Enter the number of nodes for tree 1: ";
    cin>>n;

    vector<int> nodes1(n);
    cout<<"Enter the nodes for tree 1 (use -1 for NULL): ";
    for(int i=0; i<n; i++) {
        cin>>nodes1[i];
    }

    int idx1 = 0;
    Node* root1 = buildTree(nodes1, idx1);

    cout<<"Enter the number of nodes for tree 2: ";
    cin>>n;

    vector<int> nodes2(n);
    cout<<"Enter the nodes for tree 2 (use -1 for NULL): ";
    for(int i=0; i<n; i++) {
        cin>>nodes2[i];
    }

    int idx2 = 0;
    Node* root2 = buildTree(nodes2, idx2);

    Solution sol;
    bool result = sol.isSameTree(root1, root2);
    
    if(result) {
        cout<<"The trees are identical."<<endl;
    } else {
        cout<<"The trees are not identical."<<endl;
    }

    return 0;
}