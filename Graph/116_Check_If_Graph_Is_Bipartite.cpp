/* Given an undirected graph with V vertices and adjacency list adj[], determine if the graph is bipartite. 

A graph is a bipartite if you can color all vertices using 2 colors such that no two adjacent vertices have the same color.

Equivalently: Graph contains no odd-length cycles.

Input: 0=Red, 1=Blue, 2=Red, 3=Blue -> Valid 
Output: 1
Explanation: The graph can be colored using two colors without adjacent vertices sharing the same color.
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool isBipartite(int V, vector<int> adj[]) {
        vector<int> color(V, -1); // -1: uncolored, 0: red, 1: blue

        for(int i = 0; i < V; i++) {
            if(color[i] == -1) { // If the vertex is uncolored
                queue<int> q;
                q.push(i);
                color[i] = 0; // Start coloring with red

                while(!q.empty()) {
                    int vertex = q.front();
                    q.pop();

                    for(int neighbor : adj[vertex]) {
                        if(color[neighbor] == -1) { // If the neighbor is uncolored
                            color[neighbor] = 1 - color[vertex]; // Color with opposite color
                            q.push(neighbor);
                        } else if(color[neighbor] == color[vertex]) { // If the neighbor has the same color
                            return false; // Not bipartite
                        }
                    }
                }
            }
        }
        return true; // All vertices can be colored with two colors without adjacent vertices sharing the same color
    }
};

int main() {
    int V = 4;
    vector<int> adj[V];

    adj[0] = {1, 3}; // Red
    adj[1] = {0, 2}; // Blue
    adj[2] = {1, 3}; // Red
    adj[3] = {0, 2}; // Blue

    Solution sol;
    cout<<"Is Bipartite: "<<(sol.isBipartite(V, adj) ? "True" : "False")<<endl; // Output: True

    return 0;
}