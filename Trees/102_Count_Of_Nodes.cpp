/* Count of Nodes in a Binary Tree.

Input: root = [1,2,3,4,5] 
Output: 5
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

int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);

    return leftCount + rightCount + 1;
}

int main() {
    int n;
    cout<<"Enter the number of nodes: ";
    cin>>n;

    vector<int> nodes(n);
    cout<<"Enter the nodes (use -1 for NULL): ";
    for(int i=0; i<n; i++) {
        cin>>nodes[i];
    }

    int idx = 0;
    Node* root = buildTree(nodes, idx);

    int totalNodes = countNodes(root);
    cout<<"Total number of nodes in the binary tree: "<<totalNodes<<endl;

    return 0;
}