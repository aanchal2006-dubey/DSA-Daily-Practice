/* Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Input: nums = [3, 2, 3]
Output: 3

Input: nums = [2, 2, 1, 1, 1, 2, 2]
Output: 2
*/

#include<iostream>
#include<vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int freq = 0, ans = 0;
    int n = nums.size();

    for(int i=0; i<n; i++) {
        if(freq == 0) {
            ans = nums[i];
        }
        if(ans == nums[i]) {
            freq++;
        }
        else {
            freq--;
        }
    }
    return ans;
}

int main() {
    int n;
    cout<<"Enter the size of the array:";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the elements of the array:";
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    int result = majorityElement(nums);
    cout<<"The majority element is: "<<result;

    return 0;
}