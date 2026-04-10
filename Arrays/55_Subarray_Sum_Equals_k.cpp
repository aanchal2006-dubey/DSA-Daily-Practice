/* Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k. 

A subarray is a contiguous non-empty sequence of elements within an array.

Input: nums = [1,1,1], k = 2
Output: 2
Explanation: The subarrays are [1,1] and [1,1].

Input: nums = [1,2,3], k = 3
Output: 2
Explanation: The subarrays are [1,2] and [3].
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public: 
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        vector<int> prefixSum(n, 0);

        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        map<int, int> m;
        for(int j=0; j<n; j++) {
            if(prefixSum[j] == k) {
                count++;
            }

            int val = prefixSum[j] - k;
            if(m.find(val) != m.end()) {
                count += m[val];
            }

            if(m.find(prefixSum[j]) == m.end()) {
                m[prefixSum[j]] = 0;
            }
            m[prefixSum[j]]++;
        }
        return count;
    }
};

int main() {
    int n, k;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    cout<<"Enter the value of k: ";
    cin>>k;

    Solution sol;
    int result = sol.subarraySum(nums, k);

    cout<<"Total number of subarrays whose sum equals to k: "<<result<<endl;

    return 0;
}