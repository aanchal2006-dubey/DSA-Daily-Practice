/* Given an undirected graph with V vertices and adjacency list adj[], return the BFS traversal starting from vertex 0.

You should print nodes in the order they are visited. Visit vertices level by level.

Input: V = 5, adj[] = [[1][2], [0][2][3], [0][1][4], [1][4], [2][3]]
Output: 0 1 2 3 4
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> bfs;
        vector<bool> visited(V, false);
        queue<int> q;

        // Start BFS from vertex 0
        q.push(0);
        visited[0] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            // Explore neighbors of the current node
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        return bfs;
    }        
};

int main() {
    int V = 5;
    vector<int> adj[V];
    
    // Constructing the graph
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(2);
    adj[4].push_back(3);

    Solution sol;
    vector<int> bfsResult = sol.bfsOfGraph(V, adj);

    // Print BFS traversal
    for (int node : bfsResult) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}