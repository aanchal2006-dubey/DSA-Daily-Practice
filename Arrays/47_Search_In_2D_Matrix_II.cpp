/* Write an efficient algorithm that searches for a value target in an m x n integer matrix 'matrix*. This matrix has the following properties:

    - Integer in each row are sorted in asceding from left to right.
    - Integer in each column are sorted in ascending from top to bottom.

Input: matrix = [[1, 4, 7, 11, 15], [2, 5, 8, 12, 19], [3, 6, 9, 16, 22], [10, 13, 14, 17, 24], [18, 21, 23, 26, 30]], target = 5
Output: true
Input: matrix = [[1, 4, 7, 11, 15], [2, 5, 8, 12, 19], [3, 6, 9, 16, 22], [10, 13, 14, 17, 24], [18, 21, 23, 26, 30]], target = 20
Output: false
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        int m = matrix.size();
        int n = matrix[0].size();

        int r = 0, c = n - 1;
        while(r<m && c>=0){
            if(target == matrix[r][c]){
                return true;
            }
            else if(target < matrix[r][c]){
                c--;
            }
            else{
                r++;
            }
        }
        return false;
    }
};

int main(){
    int m, n, target;
    cout<<"Enter the number of rows and columns in the matrix: ";
    cin>>m>>n;

    vector<vector<int>> matrix(m, vector<int>(n));
    cout<<"Enter the elements of the matrix: "<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }

    cout<<"Enter the target value to search: ";
    cin>>target;

    Solution sol;
    bool found = sol.searchMatrix(matrix, target);

    if(found){
        cout<<"Target "<<target<<" found in the matrix."<<endl;
    }
    else{
        cout<<"Target "<<target<<" not found in the matrix."<<endl;
    }

    return 0;
}