/* Write the code to search in rotated sorted array.

Input: nums = [4, 5, 6, 7, 0, 1, 2], target = 0
Output: 4*/

#include<iostream>
#include<vector>
using namespace std;

int search(vector<int>& nums, int target){
    int st = 0, end = nums.size()-1;
    while(st <= end){
        int mid = st + (end-st)/2;
        if(nums[mid] == target){
            return mid;
        }
        else{
            if(nums[st] <= nums[mid]){
                if(nums[st] <= target && target <= nums[mid]){
                    end = mid-1;
                }
                else {
                    st = mid + 1;
                }
            }
            else {
                if(nums[mid] <= target && target <= nums[end]){
                    st = mid + 1;
                }
                else{
                    end = mid - 1;
                }
            }
        }
    }
    return -1;
}

int main(){
    int n, target;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n;i++){
        cin>>nums[i];
    }

    cout<<"Enter the target element: ";
    cin>>target;

    int ans = search(nums, target);

    if(ans != -1){
        cout<<"Element found at index: "<<ans<<endl;
    }
    else{
        cout<<"Element not found in the array."<<endl;
    }

    return 0;
}