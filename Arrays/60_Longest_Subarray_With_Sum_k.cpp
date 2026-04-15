/* Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to k to the given value of k. If there is no subarray with sum equal to k, return 0.

Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: The longest subarray with sum 15 is [10, 5, 2, 7, 1, -10] which has length 6.

Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
Output: 5
Explanation: The longest subarray with sum -5 is [-5, 8, -14, 2, 4] which has length 5.
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        map<int, int> mp;
        int res = 0;
        int prefSum = 0;

        for(int i = 0; i < arr.size(); i++) {
            prefSum += arr[i];

            if(prefSum == k) {
                res = i + 1;
            }
            else if(mp.find(prefSum - k) != mp.end()) {
                res = max(res, i - mp[prefSum - k]);
            }

            if(mp.find(prefSum) == mp.end()) {
                mp[prefSum] = i;
            }
        }
        return res;
    }
};

int main() {
    int n, k;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    cout<<"Enter the value of k: ";
    cin>>k;

    Solution sol;
    int result = sol.longestSubarray(arr, k);

    cout<<"Length of the longest subarray with sum "<<k<<" is: "<<result<<endl;

    return 0;
}