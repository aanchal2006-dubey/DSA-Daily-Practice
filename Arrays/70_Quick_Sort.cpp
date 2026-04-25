/*
Input: arr[] = {5, 2, 6, 4, 1, 3}
Output: 1 2 3 4 5 6
*/

#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int st, int end) {
    int idx = st-1, pivot = arr[end];

    for(int j=st; j<end; j++) {
        if(arr[j] <= pivot) {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[end], arr[idx]);

    return idx;
}

void quickSort(vector<int>& arr, int st, int end) {
    if(st < end) {
        int pivIdx = partition(arr, st, end);

        quickSort(arr, st, pivIdx-1); //left half
        quickSort(arr, pivIdx+1, end);
    }
}

int main() {
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter array elements : ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    quickSort(arr, 0, n-1);

    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}