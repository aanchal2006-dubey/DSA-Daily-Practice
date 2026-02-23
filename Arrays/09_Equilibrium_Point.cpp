/* The equilibrium point in an array is an index such that the sum of all elements before that index is same as the sum of elements after it. Return -1 if no such point exists.

Input: arr[] = [1, 2, 0, 3]
Output: 2
Explaination: The sum of left of index 2 is 1 + 2 = 3 and sum on right of index 2 is 3.

Input: arr[] = [1, 1, 1, 1]
Output: -1
Explaination: There is no equilibrium index in the array.

Input: arr[] = [-7, 1, 5, 2, -4, 3, 0]
Output: 3
Explaination: The sum of left of index 3 is -7 + 1 + 5 = -1 and sum on right of index 3 is -4 + 3 + 0 = -1.
*/

#include<iostream>
#include<vector>
using namespace std;

int equilibriumPoint(vector<int> arr) {
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    int leftSum = 0;
    for (int i = 0; i < n; i++) {
        sum -= arr[i]; // sum now represents the right sum
        
        if (leftSum == sum) {
            return i; // equilibrium point found
        }
        
        leftSum += arr[i]; // update left sum for next iteration
    }
    
    return -1; // no equilibrium point found
}

int main() {
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int result = equilibriumPoint(arr);

    if(result != -1){
        cout<<"Equilibrium point is at index: "<<result<<endl;
    }
    else{
        cout<<"No equilibrium point found in the array."<<endl;
    }

    return 0;
}