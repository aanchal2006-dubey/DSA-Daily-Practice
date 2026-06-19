/* Given an integer array nums, return the length of the longest strictly increasing subsequence.

A subsequence is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

Input: nums = [10][9][2][5][3][7][101][18]
Output: 4
Explanation: The LIS is [2][3][7][101]

Input: nums = [0][1][0][3][2][3]
Output: 4
Explanation: The LIS is [0][1][2][3] 
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(), 1);
        int maxLength = 1;

        for(int i = 1; i < nums.size(); i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};

int lengthOfLISOptimized(vector<int>& nums) {
    vector<int> sub;

    for(int i=0; i<nums.size(); i++) {
        int it = lower_bound(sub.begin(), sub.end(), nums[i]) - sub.begin();
        if(it == sub.size()) {
            sub.push_back(nums[i]);
        } else {
            sub[it] = nums[i];
        }
    }
    return sub.size();
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    int result = solution.lengthOfLIS(nums);
    cout << "Length of Longest Increasing Subsequence (DP approach): " << result << endl;

    int optimizedResult = lengthOfLISOptimized(nums);
    cout << "Length of Longest Increasing Subsequence (Optimized approach): " << optimizedResult << endl;

    return 0;
}