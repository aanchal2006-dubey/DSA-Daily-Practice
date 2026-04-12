/* Check if an array is sorted

Input: arr[] = {1, 2, 3, 4, 5}
Output: Yes

Input: arr[] = {1, 2, 5, 4, 5}
Output: No
*/

#include<iostream>
#include<vector>
using namespace std;

bool isSorted(vector<int>& arr, int n) {
    if(n == 0 || n == 1) {
        return true;
    }

    return (arr[n - 1] >= arr[n - 2]) && isSorted(arr, n - 1);
}

int main() {
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    if(isSorted(arr, n)) {
        cout<<"Yes, the array is sorted."<<endl;
    } else {
        cout<<"No, the array is not sorted."<<endl;
    }

    return 0;
}