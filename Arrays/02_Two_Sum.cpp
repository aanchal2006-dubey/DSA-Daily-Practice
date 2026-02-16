/*Given an array of integer nums and an integer target, return indices of the two numbers such that they add up to target.

Input = nums = [2,7,11,15], target = 9
Output = [0,1]
Explanation = nums[0] + nums[1] = 2 + 7 = 9


Input = nums = [3, 2, 4], target = 6
Output = [1,2]
Explanation = nums[1] + nums[2] = 2 + 4 = 6
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> result;
    for(int i=0; i<nums.size(); i++) {
        for(int j=i+1; j<nums.size(); j++) {
            if(nums[i] + nums[j] == target) {
                result.push_back(i);
                result.push_back(j);
                return result;
            }
        }
    }
    return result; // Return empty if no solution found
}

int main() {
    vector<int> nums;
    int n, input, target;
    cout<<"Enter the number of elements: ";
    cin>>n;

    cout<<"Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin>>input;
        nums.push_back(input);
    }
    
    cout<<"Enter the target: ";
    cin>>target;

    vector<int> indices = twoSum(nums, target);
    if(!indices.empty()) {
        cout<<"The indices of the two numbers are: ["<<indices[0]<<","<<indices[1]<<"]"<<endl;
    } else {
        cout<<"No two numbers add up to the target."<<endl;
    }

    return 0;
}