/* Peak Index in a Mountain Array is the index of the maximum element in the array. A mountain array is defined as an array that increases to a peak element and then decreases. The peak element is the maximum element in the array.

Input: arr = [0,1,0]
Output: 1

Input: arr = [0,2,1,0]
Output: 1

Input: arr = [0,10,5,2]
Output: 1
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public: 
    int peakIndexInMountainArray(vector<int>& arr){
        int n = arr.size();
        int start = 1, end = n-2; // The peak cannot be the first or the last element

        while(start <= end){
            int mid = start + (end - start) / 2;

            // Check if mid is the peak
            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
                return mid; // Found the peak index
            }
            // If the left side is increasing, then the peak must be on the right side
            else if(arr[mid] > arr[mid - 1]){
                start = mid + 1;
            }
            // If the right side is increasing, then the peak must be on the left side
            else{
                end = mid - 1;
            }
        }
        return -1; // This line should never be reached if the input is a valid mountain array
    }
};

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    Solution sol;
    int peakIndex = sol.peakIndexInMountainArray(arr);
    cout<<"The peak index in the mountain array is: "<<peakIndex<<endl;

    return 0;
}