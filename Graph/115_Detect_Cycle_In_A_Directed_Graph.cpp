/* Given a directed graph with V vertices and adjacency list adj[], check if the graph contains a cycle.

In a directed graph, a cycle exists if you can start at a node and follow directed edges to get back to the same node.

Input: V = 3, edges = [[0,1],[1,2],[2,0]]
Output: 1
Explanation: The graph contains a cycle 0 -> 1 -> 2 -> 0.

Input: V = 4, edges = [[0,1],[1,2],[2,3]]
Output: 0
Explanation: The graph does not contain any cycle.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isCyclicUtil(int v, vector<int> adj[], vector<bool> &visited, vector<bool> &recStack) {
        if(!visited[v]) {
            visited[v] = true;
            recStack[v] = true;

            for(int i=0; i < adj[v].size(); i++) {
                int neighbor = adj[v][i];
                if(!visited[neighbor] && isCyclicUtil(neighbor, adj, visited, recStack))
                    return true;
                else if(recStack[neighbor])
                    return true;
            }
        }
        recStack[v] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for(int i = 0; i < V; i++) {
            if(isCyclicUtil(i, adj, visited, recStack))
                return true;
        }
        return false;
    }
};

int main() {
    int V = 3;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);

    Solution sol;
    cout << sol.isCyclic(V, adj) << endl; // Output: 1

    V = 4;
    vector<int> adj2[V];
    adj2[0].push_back(1);
    adj2[1].push_back(2);
    adj2[2].push_back(3);

    cout << sol.isCyclic(V, adj2) << endl; // Output: 0

    return 0;
}