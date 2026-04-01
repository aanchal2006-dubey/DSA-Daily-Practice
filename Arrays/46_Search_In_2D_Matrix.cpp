/* You are given an mxn integer matrix, matrix with the following two properties:
    1. Each row is sorted in non-decreasing order
    2. The first integer of each row is greater than the last integer of the previous row.
    
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity. 

Input: matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 6]], target = 3
Output: true

Input: matrix = [[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 6]], target = 13
Output: false
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchInRow(vector<vector<int> >& matrix, int target, int row){
        int n = matrix[0].size();
        int st = 0, end = n-1;

        while(st <= end){
            int mid = st + (end - st)/2;

            if(target == matrix[row][mid]){
                return true;
            }
            else if(target > matrix[row][mid]){
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int> >& matrix, int target){
        int m = matrix.size(), n = matrix[0].size();
        int startRow = 0, endRow = m-1;

        while(startRow <= endRow){
            int midRow = startRow + (endRow - startRow)/2;

            if(target >= matrix[midRow][0] && target <= matrix[midRow][n-1]){
                return searchInRow(matrix, target, midRow);
            }
            else if(target > matrix[midRow][0]){
                startRow = midRow + 1;
            }
            else{
                endRow = midRow - 1;
            }
        }
        return false;
    }
};

int main(){
    int m, n, target;
    cout<<"Enter the number of rows and columns in the matrix: ";
    cin>>m>>n;

    vector<vector<int> > matrix(m, vector<int>(n));
    cout<<"Enter the elements of the matrix: "<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }

    cout<<"Enter the target element to search: ";
    cin>>target;

    Solution sol;
    bool found = sol.searchMatrix(matrix, target);

    if(found){
        cout<<"Target element "<<target<<" is found in the matrix."<<endl;
    }
    else{
        cout<<"Target element "<<target<<" is not found in the matrix."<<endl;
    }

    return 0;
}