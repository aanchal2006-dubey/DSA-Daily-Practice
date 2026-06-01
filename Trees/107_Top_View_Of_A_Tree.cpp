/* Top View of a Binary Tree.

Input: preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1}
Output: 2 1 3 5
*/

#include<iostream>
#include<vector>
#include <queue>
#include<map>
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

void topView(Node* root) {
    queue<pair<Node*, int>> q;
    map<int, int> m;
    q.push({root, 0});

    while(q.size() > 0) {
        Node* curr = q.front().first;
        int line = q.front().second;
        q.pop();

        if(m.find(line) == m.end()) {
            m[line] = curr->data;
        }   

        if(curr->left != NULL) {
            q.push({curr->left, line - 1});
        }

        if(curr->right != NULL) {
            q.push({curr->right, line + 1});
        }
    }

    for(auto it : m) {
        cout << it.second << " ";
    }
    cout << endl;
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preorder);
    topView(root);
    return 0;
}