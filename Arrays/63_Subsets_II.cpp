/* Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicates subsets. Return the solution in any order.

Input: nums = [1, 2, 2]
Ouput: [[], [1], [2], [1, 2], [1, 2, 2], [2], [2, 2]]

Input: nums = [0]
Output: [[], [0]]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int> >& allSubsets) {
        int n = nums.size();
        if(i == n) {
            allSubsets.push_back(ans);
            return ;
        }

        // Include
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i+1, allSubsets);

        ans.pop_back(); // Backtracking

        int idx = i+1;
        while(idx < n && nums[idx] == nums[idx-1]) {
            idx++;
        }

        // Exclude 
        getAllSubsets(nums, ans, idx, allSubsets);
    }

    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > allSubsets;
        vector<int> result;

        getAllSubsets(nums, result, 0, allSubsets);

        return allSubsets;
    }
};

int main() {
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    Solution sol;
    vector<vector<int> > result = sol.subsetsWithDup(nums);

    cout<<"All possible subsets are: "<<endl;
    for(int i=0; i<result.size(); i++) {
        cout<<"[";
        for(int j=0; j<result[i].size(); j++) {
            cout<<result[i][j];
            if(j != result[i].size() - 1) {
                cout<<", ";
            }
        }
        cout<<"]"<<endl;
    }

    return 0;
}