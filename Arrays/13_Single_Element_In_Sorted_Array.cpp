/* This file contains the solution to finding the single element in a sorted array where every other element appears more than once

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums){
        int n = nums.size();
        int start = 0, end = n-1;

        if(n == 1){
            return nums[0];
        }

        while(start <= end){
            int mid = start + (end - start)/2;

            if(mid == 0 && nums[mid] != nums[mid+1]){
                return nums[0];
            }
            if(mid = n-1 && nums[mid] != nums[mid-1]){
                return nums[n-1];
            }

            if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]){
                return nums[mid];
            }
            else{
                if(mid%2 == 0){
                    if(nums[mid-1] == nums[mid]){
                        end = mid - 1;
                    }
                    else{
                        start = mid +1;
                    }
                }
                else{
                    if(nums[mid-1] == nums[mid]){
                        start = mid + 1;
                    }
                    else{
                        end = mid - 1;
                    }
                }
            }
        }
        return -1; // This line should never be reached if the input is valid
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
    int singleElement = sol.singleNonDuplicate(nums);
    cout<<"The single element in the sorted array is: "<<singleElement<<endl;

    return 0;
}