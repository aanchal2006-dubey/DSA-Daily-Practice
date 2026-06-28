/* You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. ALl houses at this place are arranged in a circle. That means the first house is the neighbor of the last one.

Meanwhile, adjacent houses have security systems connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Input: nums = [2][3][2]
Output: 3
Explanation: You cannot rob house 0 (money = 2) and then rob house 2 (money = 2), because they are adjacent. Rob house 1 (money = 3).
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int case1 = robLinear(nums, 0, n-2);
        int case2 = robLinear(nums, 1, n-1);

        return max(case1, case2);
    }

    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0;
        int prev1 = 0;

        for(int i=start; i<=end; i++) {
            int curr = max(prev1, prev2+nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};

int main() {
    int n;
    cout<<"Enter value of n : ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter array values : ";
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    Solution sol;
    int result = sol.rob(nums);

    cout<<"Rob : "<<result<<endl;

    return 0;
}