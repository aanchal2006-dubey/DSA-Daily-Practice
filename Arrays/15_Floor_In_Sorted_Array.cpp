/* Given a sorted array arr[] and an integer x, find the index (0-based) of the largest element in arr[] that is less than or equual to x. This element is called the floor of x. If such element does not exist, return -1.

Note - In case of multiple occurrences of ceil of x, return the index of the last occurence.

Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 5
Output: 1
Explanation: The largest element in arr[] that is less than or equal to 5 is 2, which has index 1.

Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 11
Output: 4

Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 0
Output: -1
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public: 
    int findFloor(vector<int>& arr, int x){
        int n = arr.size(), ans = -1;

        for(int i=0; i<n; i++){
            if(arr[i] <= x){
                ans = i;
            }
        }
        return ans;
    }
};

int main(){
    int n, x;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << "Enter the value of x: ";
    cin >> x;

    Solution sol;
    int result = sol.findFloor(arr, x);

    if(result != -1){
        cout << "The index of the floor of " << x << " is: " << result << endl;
    } else {
        cout << "No floor exists for " << x << " in the array." << endl;
    }

    return 0;
}