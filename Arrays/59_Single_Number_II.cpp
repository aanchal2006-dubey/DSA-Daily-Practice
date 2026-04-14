/* Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.

Input: nums = [2,2,3,2]
Output: 3

Input: nums = [0,1,0,1,0,1,99]
Output: 99
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> val;
        
        for(int i=0; i<nums.size(); i++) {
            val[nums[i]]++;
        }

        for(map<int, int>::iterator it = val.begin(); it != val.end(); it++) {
            if(it->second == 1) {
                return it->first;
            }
        }
        return -1;
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
    int result = sol.singleNumber(nums);

    cout<<"The single number in the array is: "<<result<<endl;

    return 0;
}