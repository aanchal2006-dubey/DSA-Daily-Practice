/* There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected with city c, then a and c are indirectly connected. 

A province is a group of directly or indirectly connected cities and no other cities outside the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.

Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Explanation: Cities 0 and 1 form one province, city 2 forms another province. So return 2.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int> >& isConnected, vector<bool>& visited) {
        visited[node] = true;
        int n = isConnected.size();

        for (int neighbor = 0; neighbor < n; neighbor++) {
            if (isConnected[node][neighbor] == 1 && !visited[neighbor]) {
                dfs(neighbor, isConnected, visited);
            }
        }
    }

public:
        int findCircleNum(vector<vector<int> >& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinceCount = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                provinceCount++;
                dfs(i, isConnected, visited);
            }
        }
        return provinceCount;
    }   
};

int main() {
    Solution solution;
    vector<vector<int> > isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    int result = solution.findCircleNum(isConnected);
    cout << "Number of provinces: " << result << endl; // Output: 2
    return 0;
}