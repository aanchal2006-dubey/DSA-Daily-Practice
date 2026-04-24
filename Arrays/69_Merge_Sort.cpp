/*
Input: arr[] = {12, 31, 35, 8, 32, 17}
Output: [8, 12, 17, 31, 32, 35]
*/

#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid+1;

    while(i<=mid && j<=end) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
                j++;
        }
    }

    while(i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=0; idx<temp.size(); idx++) {
        arr[idx + st] = temp[idx];
    }
}

void mergeSort(vector<int>& arr, int st, int end) {
    if(st < end) {
        int mid = st + (end-st) / 2;

        mergeSort(arr, st, mid); //left half
        mergeSort(arr, mid+1, end); //right half

        merge(arr, st, mid, end); //merge both halves
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

    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}