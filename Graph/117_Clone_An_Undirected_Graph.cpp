/* Given a reference to a node in an undirected graph, return a deep copy of the graph. 

Each node in the graph contains a value and a list of its neighbors. 

Input Graph: 1-2-3-4 , AdjList: [[2,4],[1,3],[2,4],[1,3]]
Output: Deep copy of the same structure. The new graph should have same connections but different memory addresses.
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Node {
public: 
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    map<Node*, Node*> visited; // Map to keep track of visited nodes and their copies

    Node* dfs(Node* node) {
        if(!node) return nullptr; // If the node is null, return null

        if(visited.find(node) != visited.end()) { // If the node has already been copied
            return visited[node]; // Return the copy
        }

        Node* copy = new Node(node->val); // Create a copy of the current node
        visited[node] = copy; // Mark the current node as visited and store its copy

        for(Node* neighbor : node->neighbors) { // Recursively copy all neighbors
            copy->neighbors.push_back(dfs(neighbor)); // Add the copied neighbor to the neighbors list of the copy
        }

        return copy; // Return the copy of the current node 
    }

    Node* cloneGraph(Node* node) {
        visited.clear(); // Clear the visited map before starting the cloning process
        return dfs(node); // Start the depth-first search to clone the graph
    }
};

void printGraph(Node* node, map<int, bool>& seen) {
    if(!node || seen.find(node->val) != seen.end()) return; // If the node is null or already visited, return

    seen[node->val] = true; // Mark the current node as visited
    cout << "Node " << node->val << " has neighbors: ";
    for(Node* neighbor : node->neighbors) {
        cout << neighbor->val << " "; // Print the value of each neighbor
    }
    cout << endl;

    for(Node* neighbor : node->neighbors) {
        printGraph(neighbor, seen); // Recursively print the neighbors
    }
}

int main() {
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors = {node2, node4}; // 1 is connected to 2 and 4
    node2->neighbors = {node1, node3}; // 2 is connected to 1 and 3
    node3->neighbors = {node2, node4}; // 3 is connected to 2 and 4
    node4->neighbors = {node1, node3}; // 4 is connected to 1 and 3

    Solution sol;
    Node* clonedGraph = sol.cloneGraph(node1); // Clone the graph starting from node1

    cout << "Original Graph:" << endl;
    map<int, bool> seenOriginal;
    printGraph(node1, seenOriginal); // Print the original graph

    cout << "\nCloned Graph:" << endl;
    map<int, bool> seenCloned;
    printGraph(clonedGraph, seenCloned); // Print the cloned graph

    return 0;
}