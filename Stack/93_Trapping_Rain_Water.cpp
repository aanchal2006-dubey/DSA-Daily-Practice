/* Given a non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining. 

Input: height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Output: 6
Explanation: The above elevation map is represented by the array [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]. In this case, 6 units of water are trapped. 

Input: height = [4, 2, 0, 3, 2, 5]
Output: 9
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;

        while(l < r) {
            leftMax = max(leftMax, height[l]);
            rightMax = max(rightMax, height[r]);

            if(leftMax < rightMax) {
                ans += leftMax - height[l];
                l++;
            } else {
                ans += rightMax - height[r];
                r--;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cout<<"Enter the number of elements in the height array: ";
    cin>>n;

    vector<int> height(n);
    cout<<"Enter the elements of the height array: ";
    for(int i = 0; i < n; i++) {
        cin>>height[i];
    }

    Solution sol;
    int result = sol.trap(height);
    cout<<"The amount of water trapped is: "<<result<<endl;

    return 0;
}