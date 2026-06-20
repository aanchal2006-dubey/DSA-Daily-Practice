/* Give an mxn grid filled with non-negative numbers, find a path from top-left to bottom-right that minimizes the sum of all numbers along the path.

You can only move either down or right at any point in time.

Input: grid = [[1][3][1], [1][5][1], [4][2][1]]
Output: 7
Explanation: The path 1→3→1→1→1 minimizes the sum. 
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty()) return 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < m; ++i) dp[i][0] = dp[i-1][0] + grid[i][0];
        for (int j = 1; j < n; ++j) dp[0][j] = dp[0][j-1] + grid[0][j];
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};

int minPathSumOptimal(vector<vector<int> > &grid) {
    if (grid.empty()) return 0;
    int m = grid.size(), n = grid[0].size();
    for (int i = 1; i < m; ++i) grid[i][0] += grid[i-1][0];
    for (int j = 1; j < n; ++j) grid[0][j] += grid[0][j-1];
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
        }
    }
    return grid[m-1][n-1];
}

int main() {
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;

    vector<vector<int> > grid(n);
    for (int i = 0; i < n; ++i) {
        int m;
        cout<<"Enter the number of columns for row "<<i+1<<": ";
        cin>>m;
        grid[i].resize(m);
        cout<<"Enter the elements for row "<<i+1<<": ";
        for (int j = 0; j < m; ++j) {
            cin>>grid[i][j];
        }
    }

    Solution sol;
    int result = sol.minPathSum(grid);

    cout<<"Minimum path sum: "<<result<<endl;

    return 0;
}