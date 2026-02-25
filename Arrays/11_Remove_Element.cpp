/* Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Input: nums = [3, 2, 2, 3], val=3
Output: nums = [2, 2]

Input: nums = [0, 1, 2, 2, 3, 0, 4, 2], val=2
Output: nums = [0, 1, 3, 0, 4]*/

#include<iostream>
#include<vector>
using namespace std;

int removeElement(vector<int>& nums, int val){
    int n = nums.size();
    int k=0; 

    for(int i=0; i<n; i++){
        if(nums[i] != val){
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

    int val;
    cout<<"Enter the value to remove: ";
    cin>>val;

    int newLength = removeElement(nums, val);

    cout<<"The new length of the array is: "<<newLength<<endl;
    cout<<"The modified array is: ";
    for(int i=0; i<newLength; i++){
        cout<<nums[i]<<" ";
    }

    return 0;
}