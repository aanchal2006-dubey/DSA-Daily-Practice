/* Given an array nums of distinct integers, return all the possiblepermutations. You can return the answer in any order.

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Input: nums = [1]
Output: [[1]]
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    void permutations(vector<int>& nums, vector<vector<int> >& ans, int idx){
        if(idx == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=idx; i<nums.size(); i++){
            swap(nums[idx], nums[i]);
            permutations(nums, ans, idx+1);
            swap(nums[idx], nums[i]);
        }
    }
 
    vector<vector<int> > permute(vector<int>& nums){
        vector<vector<int> > ans;

        permutations(nums, ans, 0);
        return ans;
    }
};

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    Solution sol;
    vector<vector<int> > result = sol.permute(nums);
    
    cout<<"Permutations of the array are: "<<endl;
    for(int i=0; i<result.size(); i++){
        for(int j=0; j<result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}