/* The next greater element of some element x is an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above. 

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
                - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
                - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
                - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
*/

#include<iostream>
#include<stack>
#include<map>
#include<vector>
using namespace std;    

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        map<int, int> nextGreaterMap;

        for(int i=0; i<nums2.size(); i++) {
            while(!s.empty() && s.top() < nums2[i]) {
                nextGreaterMap[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }

        vector<int> result(nums1.size());
        for(int i=0; i<nums1.size(); i++) {
            result[i] = nextGreaterMap.count(nums1[i]) ? nextGreaterMap[nums1[i]] : -1;
        }

        return result;
    }
};

int main() {
    int n1, n2;
    cout<<"Enter the size of nums1: ";
    cin>>n1;
    cout<<"Enter the size of nums2: ";
    cin>>n2;

    vector<int> nums1(n1), nums2(n2);
    cout<<"Enter the elements of nums1: ";
    for(int i=0; i<n1; i++) {
        cin>>nums1[i];
    }
    cout<<"Enter the elements of nums2: ";
    for(int i=0; i<n2; i++) {
        cin>>nums2[i];
    }

    Solution sol;
    vector<int> result = sol.nextGreaterElement(nums1, nums2);

    cout<<"Next Greater Elements: ";
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }

    return 0;
}