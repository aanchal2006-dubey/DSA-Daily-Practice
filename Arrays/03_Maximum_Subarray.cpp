/* Given an integer array nums, find the subarray with the largest sum, and return its sum.

Input: nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
Output: 6
Explanation: The subarray [4, -1, 2, 1] has the largest sum 6.*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum = nums[0];
        int current_sum = 0;
        
        for (int num : nums) {
            current_sum += num;
            max_sum = max(max_sum, current_sum);
            if (current_sum < 0) {
                current_sum = 0;
            }
        }
        
        return max_sum;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    int result = solution.maxSubArray(nums);
    cout << "Maximum subarray sum: " << result << endl; // Output: 6

    return 0;
}