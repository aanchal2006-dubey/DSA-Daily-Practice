/* Given an undirected graph with V vertices and adjacency list adj[], determine if the graph contains a cycle.

A cycle exists if you can start at a node and follow edges back to the same node without repeating any edge.

Input: V = 3, adj = [[1][2], [0][2], [0][1]]
Output: true - The graph contains a cycle (0-1-2-0)
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isCyclicUtil(int v, vector<int> adj[], vector<bool>& visited, int parent) {
        visited[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                if (isCyclicUtil(neighbor, adj, visited, v)) {
                    return true;
                }
            } else if (neighbor != parent) {
                return true; // A cycle is detected
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (isCyclicUtil(i, adj, visited, -1)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    int V = 3;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(1);

    Solution solution;
    bool hasCycle = solution.isCycle(V, adj);
    cout << (hasCycle ? "true" : "false") << endl; // Output: true

    return 0;
}