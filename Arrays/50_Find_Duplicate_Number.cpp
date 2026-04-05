/* Given an array of integers nums containing n+1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.

Input: nums = [1,3,4,2,2]
Output: 2

Input: nums = [3, 3, 3, 3, 3]
Output: 3
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:  
    int findDuplicate(vector<int>& nums){
        map<int, int> freq;
        int n = nums.size();
        int ans = -1;

        for(int i=0; i<n; i++){
            freq[nums[i]]++;
        }

        for(int i=0; i<n; i++){
            if(freq[nums[i]] > 1){
                ans = nums[i];
                break;
            }
        }
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
    int duplicate = sol.findDuplicate(nums);

    cout<<"The duplicate number is: "<<duplicate<<endl;

    return 0;
}