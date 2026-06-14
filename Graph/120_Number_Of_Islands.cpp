/* Given an mxn 2D binary grid where 1 represents land and 0 represents water, return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. Assume all four edges of the grid are surrounded by water. 

Input Format:
    The first line contains two integers m and n: grid dimensions.
    The next m lines contain n integers each (0 or 1).

Example Input:
    4 5
    1 1 0 0 0
    1 1 0 0 0
    0 0 1 0 0
    0 0 0 1 1

Example Output:
    3

Explanation:
    There are three islands in the given grid. The first island is formed by the first two rows and the first two columns, the second island is formed by the third row and the third column, and the third island is formed by the last two rows and the last two columns.
*/

#include<iostream>
#include<vector>
using namespace std;

void dfs(int i, int j, vector<vector<char> >& grid, int m, int n) {
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
        return;
    }
    grid[i][j] = '0'; // Mark the cell as visited
    dfs(i + 1, j, grid, m, n); // Down
    dfs(i - 1, j, grid, m, n); // Up
    dfs(i, j + 1, grid, m, n); // Right
    dfs(i, j - 1, grid, m, n); // Left
}

int numIslands(vector<vector<char> >& grid) {
    if (grid.empty()) return 0;
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                ++count;
                dfs(i, j, grid, m, n);
            }
        }
    }
    return count;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char> > grid(m, vector<char>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }
    cout << numIslands(grid) << endl;
    return 0;
}