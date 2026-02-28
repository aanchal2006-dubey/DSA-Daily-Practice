/* Remove Duplicates elements from a sorted array.

Input: nums = [1, 1, 2]
Output: nums = [1, 2]

Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: nums = [0,1,2,3,4]
*/

#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& nums){
    int n = nums.size();

    if(n == 0) return 0;

    int k = 1;
    for(int i=1; i<n; i++){
        if(nums[i] != nums[i-1]){
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }

    int k = removeDuplicates(nums);
    cout<<"The array after removing duplicates is: ";
    for(int i=0; i<k; i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}