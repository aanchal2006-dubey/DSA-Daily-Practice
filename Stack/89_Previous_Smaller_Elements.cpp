/* Previous Smaller Elements.

Input: arr = [3, 1, 0, 8, 6]
Output: [-1, -1, -1, 0, 0]
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> prevSmallerElements(vector<int>& arr) {
    vector<int> ans(arr.size(), 0);
    stack<int> s;

    for(int i=0; i<arr.size(); i++) {
        while(s.size() > 0 && s.top() >= arr[i]) {
            s.pop();
        }
        if(s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }

    return ans;
}

int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    vector<int> result = prevSmallerElements(arr);

    cout<<"Previous Smaller Elements: ";
    for(int i=0; i<result.size(); i++) {
        cout<<result[i]<<" ";
    }

    return 0;
}