/* Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]).

The next greater element of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's greater number is 2; The number 2 can't find next greater number; The second 1's greater number needs to search circularly, which is also 2.

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
Explanation: The first 1's greater number is 2; The second 2's greater number is 3; The first 3's greater number is 4; The number 4 can't find next greater number; The second 3's greater number needs to search circularly, which is 4.
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> st; // stack to store indices

        for (int i = 0; i < 2 * n; ++i) {
            int num = nums[i % n]; // circular indexing
            while (!st.empty() && nums[st.top()] < num) {
                res[st.top()] = num; // update the result for the index at the top of the stack
                st.pop(); // pop the index from the stack
            }
            if (i < n) { // only push indices from the first pass
                st.push(i);
            }
        }

        return res;
    }
};

int main() {
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }

    Solution sol;
    vector<int> result = sol.nextGreaterElements(nums);

    cout<<"Next greater elements: ";
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }

    return 0;
}