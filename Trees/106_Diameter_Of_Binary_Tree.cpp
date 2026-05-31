/* Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the longest path between any two nodes in the tree.

Input: root = [1,2]
Output: 1
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
    int ans = 0;

    int height(Node* root) {
        if(root == NULL) {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        ans = max(ans, leftHeight + rightHeight);

        return max(leftHeight, rightHeight) + 1;
    }

    int diameterOfBinaryTree(Node* root) {
        height(root);

        return ans;
    }
};

int main() {
    vector<int> nodes = {1, 2, 3, 4, 5};
    Node* root = buildTreeLevelOrder(nodes);

    Solution sol;
    int diameter = sol.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree: " << diameter << endl;

    return 0;
}