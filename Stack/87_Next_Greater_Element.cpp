/* Next Greater Element 

Input: arr = [6, 8, 0, 1, 3]
Output: [8, -1, 1, 3, -1]
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    stack<int> s;
    vector<int> result(n, -1);

    for(int i=0; i<n; i++) {
        while(!s.empty() && arr[s.top()] < arr[i]) {
            result[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    cout<<"Next Greater Elements: ";
    for(int i=0; i<n; i++) {
        cout<<result[i]<<" ";
    }

    return 0;
}