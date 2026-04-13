/*Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorith with O(log n) runtime complexity.

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int binSearch(vector<int>& nums, int target, int st, int end) {
        if(st <= end) {
            int mid = st + (end - st) / 2;

            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                return binSearch(nums, target, mid + 1, end);
            }
            else {
                return binSearch(nums, target, st, mid - 1);
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        return binSearch(nums, target, 0, nums.size() - 1);
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

    cout<<"Enter the target element to search: ";
    cin>>target;

    Solution sol;
    int result = sol.search(nums, target);

    cout<<"The index of the target element is: "<<result<<endl;

    return 0;
}