/* You are given an undirected unweighted graph with n vertices numbered from 1 to n and m edges. Find the shortest path in terms of numbers of edges from vertex 1 to vertex n. If no such exists, return -1.

Input: n = 5, m = 5, edges = [[1, 2], [1, 3], [2, 4], [3, 4], [4, 5]]
Output: 3
Explanation: The shortest path from vertex 1 to vertex 5 is 1 -> 2 -> 4 -> 5, which has 3 edges.
*/

#include <iostream>
#include <vector>
#include <queue>
#include<climits>
#include<math.h>
using namespace std;

int shortestPath(int n, vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n + 1);

    for(const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n+1, INT_MAX);
    dist[1] = 0;
    queue<int> q;
    q.push(1);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == INT_MAX) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }

    return dist[n] == INT_MAX ? -1 : dist[n];
}

int main() {
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<pair<int, int>> edges(m);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    int result = shortestPath(n, edges);
    if (result != -1) {
        cout << "The shortest path from vertex 1 to vertex " << n << " is: " << result << " edges." << endl;
    } else {
        cout << "No path exists from vertex 1 to vertex " << n << "." << endl;
    }

    return 0;
}