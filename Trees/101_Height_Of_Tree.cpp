/* Max distance from root to any leaf node.

Input: nodes = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1}
Output: 3
*/

#include<iostream>
#include<vector>
#include<algorithm>
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

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
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

    cout<<"Height of the tree: "<<height(root)<<endl;

    return 0;
}