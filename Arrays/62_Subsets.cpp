/* Given an integer array nums of unique elements, return all possible subsets (the power set).

The Solution set must not contain duplicate subsets. Return the solution in any order.

Input: nums = [1, 2, 3]
Output: [[], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]]

Input: nums = [0]
Output: [[], [0]]
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int> >& allSubsets) {
        if(i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }

        // include the current element
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, allSubsets);

        ans.pop_back(); // backtrack

        // exclude the current element
        getAllSubsets(nums, ans, i + 1, allSubsets);
    }

    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > allSubsets;
        vector<int> ans;

        getAllSubsets(nums, ans, 0, allSubsets);

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
    vector<vector<int> > result = sol.subsets(nums);

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