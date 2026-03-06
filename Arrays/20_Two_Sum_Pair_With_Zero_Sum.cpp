/* Given an integer array arr, return all the unique pairs [arr[i],arr[j]] such that i != j and arr[i] + arr[j] == 0.

Note: The pairs must be returned in sorted order, the solution array should also be sorted, and the answer must not contain any duplicate pairs.

Input: arr = [-1, 0, 1, 2, -1, -4]
Output: [[-1, 1]]
Explaination: arr[0] + arr[2] == 0, arr[4] + arr[2] == 0, but the pair [-1, 1] is repeated twice in the output, so we only return it once.

Input: arr = [6, 1, 8, 0, 4, -9, -1, -10, -6, -5]
Output:[[-6, 6], [-1, 1]]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > twoSum(vector<int> &arr) {
    vector<vector<int> > result;
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for(int i = 0; i < n - 1; i++) {
        if(i > 0 && arr[i] == arr[i - 1]) continue; // Skip duplicates
        int left = i + 1, right = n - 1;
        while(left < right) {
            int sum = arr[i] + arr[left];
            if(sum == 0) {
                result.push_back({arr[i], arr[left]});
                while(left < right && arr[left] == arr[left + 1]) left++; // Skip duplicates
                while(left < right && arr[right] == arr[right - 1]) right--; // Skip duplicates
                left++;
                right--;
            } else if(sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<vector<int> > result = twoSum(arr);
    for(int i = 0; i < result.size(); i++) {
        cout << "[" << result[i][0] << ", " << result[i][1] << "]" << endl;
    }
    return 0;
}