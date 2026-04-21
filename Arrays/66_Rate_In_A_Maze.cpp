/*
maze[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: [["DDRDRR"], ["DRDDRR"]]
*/

#include<iostream>
#include<vector>
using namespace std;

void helper(vector<vector<int> >& mat, int r, int c, string path, vector<string>& ans) {
    int n = mat.size();
    if(r<0 || c<0 || r>=n || c>=n || mat[r][c] == 0 || mat[r][c] == -1) {
        return; //out of bounds or blocked cell
    }
    if(r == n-1 && c == n-1) {
        ans.push_back(path); //reached destination
        return;
    }
    mat[r][c] = -1; //mark the cell as visited

    helper(mat, r+1, c, path+"D", ans); //down
    helper(mat, r-1, c, path+"U", ans); //up
    helper(mat, r, c-1, path+"L", ans); //left
    helper(mat, r, c+1, path+"R", ans); //right

    mat[r][c] = 1;
}

vector<string> findPath(vector<vector<int> >& mat) {
    int n = mat.size();

    vector<string> ans;
    string path = "";

    helper(mat, 0, 0, path, ans);

    return ans;
}

int main() {
    int n;
    cout << "Enter the size of the square maze (N): ";
    cin >> n;

    // Initializing the NxN matrix
    vector<vector<int> > mat(n, vector<int>(n));

    cout << "Enter the maze elements (1 for path, 0 for wall):" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    vector<string> result = findPath(mat);

    if(result.empty()) {
        cout << "No path exists from source to destination." << endl;
    } else {
        cout << "The possible paths are: " << endl;
        // Simple for loop to print all found paths
        for(int i = 0; i < result.size(); i++) {
            cout << "\"" << result[i] << "\" ";
        }
        cout << endl;
    }

    return 0;
}