/* Sum of all nodes in a binary tree.

Input: root = [1,2,3,4,5] 
Output: 15
Explanation: The sum of all nodes in the binary tree is 15.
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

int Sum(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftSum = Sum(root->left);
    int rightSum = Sum(root->right);

    return leftSum + rightSum + root->data;
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

    int totalSum = Sum(root);
    cout<<"Sum of all nodes in the binary tree: "<<totalSum<<endl;

    return 0;
}