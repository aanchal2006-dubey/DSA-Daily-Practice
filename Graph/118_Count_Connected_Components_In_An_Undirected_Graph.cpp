/* Given an undirected graph with n vertices labeled from 1 to n and m edges, determine the number of connected components in the graph.

A connected component is a maximal set of vertices such that each pair of vertices in the set is connected by a path.

Input: The first line contains two integers n and m (1 <= n <= 1000, 0 <= m <= 1000), representing the number of vertices and edges in the graph. 
The next m lines contain two integers u and v (1 <= u, v <= n), representing an edge between vertices u and v.

Output: Output a single integer, the number of connected components in the graph.

Example:
Input: 5 3
1 2 
2 3
4 5
Output: 2
*/

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int countConnectedComponents(int n, vector<vector<int>>& graph) {
    vector<bool> visited(n + 1, false);
    int count = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited);
            count++;
        }
    }

    return count;
}

int main() {
    int n, m;
    cout<< "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int result = countConnectedComponents(n, graph);
    cout << "The number of connected components is: " << result << endl;

    return 0;
}