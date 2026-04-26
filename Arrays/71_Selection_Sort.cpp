/*
Input: arr[] = {2, 4, 6, 1, 3, 5}
Output: 1 2 3 4 5 6
*/

#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int> &arr, int n){
    for(int i=0; i<n-1; i++){
        int smallestIdx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[smallestIdx]){
                smallestIdx = j;
            }
        }
        swap(arr[i], arr[smallestIdx]);
    }
}

void printArray(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {4, 1, 5, 2, 3};
    int n = 5;

    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}