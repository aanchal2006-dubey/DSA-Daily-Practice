/* Sort an array of 0s, 1s and 2s.

Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
Input: N = 5
arr[] = {0, 2, 1, 2, 0}
Output: 0 0 1 2 2
Explanation: 0s 1s and 2s are segregated into ascending order.

Input: N = 3
arr[] = {0, 1, 0}
Output: 0 0 1
Explanation: 0s 1s and 2s are segregated into ascending order.
*/

#include<iostream>
#include<vector>
using namespace std;

void sort012(vector<int>& arr, int n){
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            mid++;
            low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of the array (0s, 1s, and 2s): ";
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    sort012(arr, n);

    cout<<"Sorted array: ";
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}