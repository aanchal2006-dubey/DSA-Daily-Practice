/* Given a Directed Acyclic Graph (DAG) with V vertices and adjacency list adj[][], return a topological ordering of the vertices.

Topological sort = linear ordering of vertices such that for every directed edge u -> v, vertex u comes before vertex v in the ordering.

If the graph has a cycle, topological sort is not possible.

Input: V = 6, Edges = [[5, 0], [5, 2], [4, 0], [4, 1], [2, 3], [3, 1]]
Output: [5, 4, 2, 3, 1, 0] - One possible topological ordering of the vertices.
Explanation: 5 comes before 0 and 2, 4 comes before 0 and 1, 2 comes before 3, and 3 comes before 1.
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    void topologicalSortUtil(int v, vector<int> adj[], vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;

        for (int neighbor : adj[v]) {
            if (!visited[neighbor]) {
                topologicalSortUtil(neighbor, adj, visited, Stack);
            }
        }
        Stack.push(v); // Push the vertex to the stack after visiting all its neighbors
    }

    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        stack<int> Stack;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                topologicalSortUtil(i, adj, visited, Stack);
            }
        }

        vector<int> topoOrder;
        while (!Stack.empty()) {
            topoOrder.push_back(Stack.top());
            Stack.pop();
        }
        return topoOrder;
    }
};

int main() {
    int V = 6;
    vector<int> adj[V];
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution solution;
    vector<int> topoOrder = solution.topoSort(V, adj);
    
    cout << "Topological Sort: ";
    for (int vertex : topoOrder) {
        cout << vertex << " ";
    }
    cout << endl; // Output: Topological Sort: 5 4 2 3 1 0

    return 0;
}