/*
Input: arr[] = {1, 3, 5, 10, 2, 6, 8, 9}
Output: 6

Inversion is a pair which follows the following conditions:
    for(arr[i], arr[j])
    (i) i<j
    (ii) arr[i] > arr[j]
*/

#include<iostream>
#include<vector>
using namespace std;

int merge(vector<int>& arr, int st, int mid, int end) {
    vector<int> temp;
    int i=st, j=mid+1;
    int invCount = 0;

    while(i <= mid && j <= end) {
        if(arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
            invCount += (mid-i+1); //count inversions 
        }
    }

    while(i <= mid) { //for remaining elements
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    for(int idx=0; idx<temp.size(); idx++) {
        arr[idx+st] = temp[idx];
    }

    return invCount;
}

int mergeSort(vector<int>& arr, int st, int end) {
    if(st < end) {
        int mid = st + (end-st) / 2;

        int leftInvCount = mergeSort(arr, st, mid);
        int rightInvCount = mergeSort(arr, mid+1, end);

        int invCount = merge(arr, st, mid, end);

        return leftInvCount + rightInvCount + invCount;
    }

    return 0;
}

int main() {
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter array elements: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    int ans = mergeSort(arr, 0, n-1);
    cout<<"Inversion Count: "<<ans<<endl;

    return 0;
}