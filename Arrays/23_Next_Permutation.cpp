/* A solution to find the next permutation of an array of integers. 

arr = [1, 2, 3] Return lexicographically next greater permutation of arr. If such arrangement is not possible, it must rearrange it as the lowest possible order (i.e., sorted in ascending order).

Ouput: [1, 3, 2]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& arr){
        int n = arr.size();
        int pivot = -1;

        for(int i=n-2; i>=0; i--){
            if(arr[i] < arr[i+1]){
                pivot = i;
                break;
            }
        }
        if(pivot == -1){
            reverse(arr.begin(), arr.end());
        }

        for(int i=n-1; i>pivot; i--){
            if(arr[i] > arr[pivot]){
                swap(arr[i], arr[pivot]);
                break;
            }
        }

        int left = pivot + 1, right = n - 1;
        while(left < right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
};

int main(){
    vector<int> arr = {1, 2, 3};
    Solution sol;
    sol.nextPermutation(arr);
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}