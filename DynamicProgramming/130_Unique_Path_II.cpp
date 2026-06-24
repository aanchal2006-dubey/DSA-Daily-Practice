/* You are given an m x n integer array obstacleGrid. A robot is initially located at the top-left corner. The robot tries to move to the bottom-right corner.

The robot can only move either down or right at any point in time. An obstacle and space are marked as 1 or 0 respectively in obstacleGrid. A path cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above. There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down   
2. Down -> Down -> Right -> Right
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // If the starting cell has an obstacle, then return 0 as there are no paths.
        if (obstacleGrid[0][0] == 1) return 0;
        
        // Create a DP table to store the number of unique paths to each cell.
        vector<vector<int> > dp(m, vector<int>(n, 0));
        
        // Initialize the starting position
        dp[0][0] = 1;
        
        // Fill the first column
        for (int i = 1; i < m; ++i) {
            dp[i][0] = (obstacleGrid[i][0] == 0 && dp[i-1][0] == 1) ? 1 : 0;
        }
        
        // Fill the first row
        for (int j = 1; j < n; ++j) {
            dp[0][j] = (obstacleGrid[0][j] == 0 && dp[0][j-1] == 1) ? 1 : 0;
        }
        
        // Fill the rest of the DP table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                } else {
                    dp[i][j] = 0; // If there's an obstacle, no paths lead to this cell.
                }
            }
        }
        
        return dp[m-1][n-1]; // The bottom-right corner will have the total unique paths.
    }
};

int main() {
    int n;
    cout<<"Enter the number of rows: ";
    cin>>n;

    int m;
    cout<<"Enter the number of columns: ";  
    cin>>m;

    vector<vector<int> > obstacleGrid(n, vector<int>(m));
    cout<<"Enter the grid values (0 for empty cell, 1 for obstacle):"<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>obstacleGrid[i][j];
        }
    }

    Solution Sol;
    int result = Sol.uniquePathsWithObstacles(obstacleGrid);

    cout<<"Unique Path Grid : "<<result<<endl;

    return 0;
}