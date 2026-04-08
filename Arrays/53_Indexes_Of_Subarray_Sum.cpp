/* Given an array arr[] containing only non-negative integers, your task is to find a continuous subarray whose sum equals a specified value target. You need to return the 1-based indices of the leftmost and rightmost elements of this subarray. You need to find the first subarray whose sum is equal to the target.

Note: If no such array is possible then, return -1.
Input: arr[] = {1, 2, 3, 7, 5}, target = 12
Output: [2, 4]
Explanation: The sum of elements from 2nd to 4th position is 12.

Input: arr = [5, 3, 4], target = 12
Output: [-1]
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    vector<int> subarraySum(vector<int> arr, int target){
        int n = arr.size();
        vector<int> result;

        for(int s=0; s<n; s++){
            int currSum = 0;

            for(int e=s; e<n; e++){
                currSum += arr[e];

                if(currSum == target){
                    result.push_back(s + 1);
                    result.push_back(e + 1);
                    return result;
                }
            }
        }
        result.push_back(-1);
        return result;
    }
};

int main() {
    int n, target;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<"Enter the target sum: ";
    cin>>target;

    Solution sol;
    vector<int> result = sol.subarraySum(arr, target);

    if(result.size() == 1 && result[0] == -1) {
        cout<<"No subarray found with the given target sum."<<endl;
    } else {
        cout<<"Subarray found at indices: ["<<result[0]<<", "<<result[1]<<"]"<<endl;
    }

    return 0;
}