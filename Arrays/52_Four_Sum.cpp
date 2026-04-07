/* Given an integer array nums, return all unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that: 
0 <= a, b, c, d < nums.length
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; // Skip duplicates
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++; // Skip duplicates
                        while (left < right && nums[right] == nums[right - 1]) right--; // Skip duplicates
                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return res;
    }  
};

int main() {
    int n, target;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    cout<<"Enter the target sum: ";
    cin>>target;

    Solution sol;
    vector<vector<int>> result = sol.fourSum(nums, target);

    cout<<"Quadruplets that sum to "<<target<<": "<<endl;
    for(int i=0; i<result.size(); i++) {
        cout<<"[";
        for(int j=0; j<result[i].size(); j++) {
            cout<<result[i][j];
            if(j < result[i].size() - 1) cout<<", ";
        }
        cout<<"]"<<endl;
    }

    return 0;
}