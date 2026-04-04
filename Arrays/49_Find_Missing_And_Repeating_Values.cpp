/* You are given a 0-indexed 2D integer matrix grid of size n*n with values in the range [1, n^2]. Each integer appears exactly once except 'a' which appears twice and 'b' which is missing. The task is to find the repeating and missing numbers a and b.

Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

Input: grid = [[1, 3], [2, 2]]
Output: [2, 4]

Input: grid = [[9, 1, 7], [8, 9, 2], [3, 4, 6]]
Output: [9, 5]
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<vector<int> >& grid) {
        vector<int> ans;
        set<int> s;
        int n = grid.size();
        int a, b;

        int expSum = 0, actualSum = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++){
                actualSum += grid[i][j];

                if(s.find(grid[i][j]) != s.end()){
                    a = grid[i][j];
                    ans.push_back(a);
                }
                s.insert(grid[i][j]);
            }
        }
        
        expSum = (n*n * (n*n + 1)) / 2;
        b = expSum + a - actualSum;
        ans.push_back(b);

        return ans;
    }
};

int main(){
    int n, m;
    cout<<"Enter the size of the grid: ";
    cin>>n>>m;

    vector<vector<int> > grid(n, vector<int>(m));
    cout<<"Enter the elements of the grid: "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid[i][j];
        }
    }

    Solution sol;
    vector<int> ans = sol.findErrorNums(grid);

    cout<<"Repeating number: "<<ans[0]<<endl;
    cout<<"Missing number: "<<ans[1]<<endl;

    return 0;
}