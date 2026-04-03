/* Given an mxn matrix, return all elements of the matrix in spiral order.

Input: matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
Output: [1, 2, 3, 6, 9, 8, 7, 4, 5] */

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        int srow = 0, scol = 0, erow = m-1, ecol = n-1;
        vector<int> ans;

        while(srow <= erow && scol <= ecol){
            for(int i=scol; i<=ecol; i++){
                ans.push_back(matrix[srow][i]);
            }
            srow++;

            for(int i=srow; i<=erow; i++){
                ans.push_back(matrix[i][ecol]);
            }
            ecol--;

            if(srow <= erow){
                for(int i=ecol; i>=scol; i--){
                    ans.push_back(matrix[erow][i]);
                }
                erow--;
            }

            if(scol <= ecol){
                for(int i=erow; i>=srow; i--){
                    ans.push_back(matrix[i][scol]);
                }
                scol++;
            }
        }
        return ans;
    }
};

int main(){
    int m, n;
    cout<<"Enter the number of rows and columns in the matrix: ";
    cin>>m>>n;

    vector<vector<int> > matrix(m, vector<int>(n));
    cout<<"Enter the elements of the matrix: "<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>matrix[i][j];
        }
    }

    Solution sol;
    vector<int> result = sol.spiralOrder(matrix);

    cout<<"Spiral order of the matrix is: ";
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}