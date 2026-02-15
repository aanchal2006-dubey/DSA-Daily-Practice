#include<iostream>
#include<vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;
    for(int num : nums) {
        result ^= num;
    }
    return result;
}

int main() {
    vector<int> nums;
    int n, input;
    cout<<"Enter the number of elements: ";
    cin>>n;

    cout<<"Enter the elements: ";
    for(int i = 0; i < n; i++) {
        cin>>input;
        nums.push_back(input);
    }
    int single = singleNumber(nums);
    cout<<"The single number is: "<<single<<endl;

    return 0;
}