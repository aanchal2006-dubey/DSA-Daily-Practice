/* There is a knight on an nxn chessboard. In a valid configuration, the knight starts at the top-left cell of the board and visits every cell on the board exactly once.

You are given an nxn integer matrix grid consisting of distinct integers from the range [0, n * n - 1], where grid[row][col] indicates that the cell (row, col) was visited at the (grid[row][col])th step of the journey. The moves are 0-indexed.

Return true if grid represents a valid configuration of the knight's movements or false otherwise.

Note - A valid knight move consists of moving two squares vertically and one square horizontally, or two squares horizontally adn one square vertically.

Input: grid = [[0, 11, 16, 5, 20], [17, 4, 19, 10, 15], [12, 1, 8, 21, 6], [3, 18, 23, 14, 9], [24, 13, 2, 7, 22]]
Output: true
Explanation: The above configuration is a valid knight tour. One possible way to visit every cell is: (0, 0) -> (2, 1) -> (0, 2) -> (1, 0) -> (3, 1) -> (4, 3) -> (2, 4) -> (0, 3) -> (1, 1) -> (3, 0) -> (4, 2) -> (2, 3) -> (0, 4) -> (1, 2) -> (3, 3) -> (4, 0) -> (2, 1) -> (0, 2) -> (1, 0) -> (3, 1) -> (4, 3) -> (2, 4) -> (0, 3) -> (1, 1) -> (3, 0) -> (4, 2) -> (2, 3) -> (0, 4) -> (1, 2) -> (3, 3) -> (4, 0) -> (2, 1) -> (0, 2) -> (1, 0) -> (3, 1) -> (4, 3) -> (2, 4) -> (0, 3) -> (1, 1) -> (3, 0) -> (4, 2) -> (2, 3) -> (0, 4) -> (1, 2) -> (3, 3) -> (4, 0) -> (2, 1) -> (0, 2) -> (1, 0) -> (3, 1) -> (4, 3) -> (2, 4) -> (0, 3) -> (1, 1) -> (3, 0) -> (4, 2) -> (2, 3) -> (0, 4) -> (1, 2) -> (3, 3) -> (4, 0) -> (2, 1) -> (0, 2) -> (1, 0) -> (3, 1) -> (4, 3) -> (2, 4) -> (0, 3) -> (1, 1) -> (3, 0) -> (4, 2) -> (2, 3) -> (0, 4) -> (1, 2) -> (3, 3) -> (4, 0)

Input: grid = [[0, 3, 6], [5, 8, 1], [2, 7, 4]]
Output: false
Explanation: There is no valid knight tour for this configuration.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<int> >& grid, int r, int c, int n, int expVal) {
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c] != expVal) {
            return false;
        }

        if(expVal == n*n-1) {
            return true;
        }

        //8 possible moves for a knight
        int ans1 = isValid(grid, r-2, c+1, n, expVal+1);
        int ans2 = isValid(grid, r-1, c+2, n, expVal+1);
        int ans3 = isValid(grid, r+1, c+2, n, expVal+1);
        int ans4 = isValid(grid, r+2, c+1, n, expVal+1);
        int ans5 = isValid(grid, r+2, c-1, n, expVal+1);
        int ans6 = isValid(grid, r+1, c-2, n, expVal+1);
        int ans7 = isValid(grid, r-1, c-2, n, expVal+1);
        int ans8 = isValid(grid, r-2, c-1, n, expVal+1);

        return ans1 || ans2 || ans3 || ans4 || ans5 || ans6 || ans7 || ans8;
    }

    bool checkValidGrid(vector<vector<int> >& grid) {
        return isValid(grid, 0, 0, grid.size(), 0);
    }
};

int main() {
    int n;
    cout<<"Enter the size of the grid: ";
    cin>>n;

    vector<vector<int> > grid(n, vector<int>(n));
    cout<<"Enter the grid: "<<endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>grid[i][j];
        }
    }

    Solution sol;
    bool result = sol.checkValidGrid(grid);
    if(result) {
        cout<<"The grid represents a valid knight's tour configuration."<<endl;
    } else {
        cout<<"The grid does not represent a valid knight's tour configuration."<<endl;
    }

    return 0;
}