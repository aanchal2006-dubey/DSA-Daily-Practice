/* You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water. 

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int maxArea(vector<int>& height){
        int maxWater = 0;
        int left = 0, right = height.size() - 1;

        while(left < right){
            int w = right - left;
            int ht = min(height[left], height[right]);
            int currWater = w * ht;
            maxWater = max(maxWater, currWater);

            height[left] < height[right] ? left++ : right--;
        }
        return maxWater;
    }
};

int main(){
    int n;
    cout<<"Enter the number of elements in the height array: ";
    cin>>n;

    vector<int> height(n);
    cout<<"Enter the elements of the height array: ";
    for(int i=0; i<n; i++){
        cin>>height[i];
    }

    Solution sol;
    int result = sol.maxArea(height);
    cout<<"The maximum amount of water a container can store is: "<<result<<endl;

    return 0;
}