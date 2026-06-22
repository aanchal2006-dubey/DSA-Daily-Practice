/* Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal, or false otherwise.

Input: nums = [1,5,11,5] 
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11]. Both sum to 11.


Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into two subsets with equal sums.
*/

#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num = 0; num < nums.size(); ++num) {
            for (int j = target; j >= nums[num]; --j) {
                dp[j] = dp[j] || dp[j - nums[num]];
            }
        }
        return dp[target];
    }
};

bool canPartitionOptimized(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;

    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for(int num = 0; num < nums.size(); ++num) {
        for(int j = target; j >= nums[num]; --j) {
            dp[j] = dp[j] || dp[j - nums[num]];
        }
    }
    return dp[target];
}

int main() {
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i = 0; i < n; ++i) {
        cin>>nums[i];
    }

    Solution solution;
    if(solution.canPartition(nums)) {
        cout<<"The array can be partitioned into two subsets with equal sum."<<endl;
    } else {
        cout<<"The array cannot be partitioned into two subsets with equal sum."<<endl;
    }

    if(canPartitionOptimized(nums)) {
        cout<<"(Optimized) The array can be partitioned into two subsets with equal sum."<<endl;
    } else {
        cout<<"(Optimized) The array cannot be partitioned into two subsets with equal sum."<<endl;
    }

    return 0;
}