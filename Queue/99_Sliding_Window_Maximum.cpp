/* You are given an array of integers nums, there is a sliding window of size k, which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. 

Return the max sliding window.

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               ----- 
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3   5] 3  6  7       5
 1  3 -1 [-3   5   3] 6  7       5
 1  3 -1 -3 [5   3   6] 7       6
 1  3 -1 -3  5 [3   6   7]       7

Input: nums = [1], k = 1
Output: [1]
*/

#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq; // store the index of the elements in the current window
        for (int i = 0; i < nums.size(); i++) {
            // remove the elements which are out of this window
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            // remove the elements which are smaller than the current element
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            // add the current element at the back of the deque
            dq.push_back(i);
            // if the window has hit size k, add to results (the front of the deque is the largest element in the window)
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};

int main() {
    int n, k;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    cout<<"Enter the size of the sliding window: ";
    cin>>k;

    Solution sol;
    vector<int> result = sol.maxSlidingWindow(nums, k);

    cout<<"The maximum values in each sliding window are: ";
    for(int i : result) {
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}