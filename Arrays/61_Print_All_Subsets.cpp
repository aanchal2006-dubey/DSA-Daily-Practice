/* Print All Subsets.

Input: arr[] = {1, 2, 3}
Output: 123, 12, 13, 23, 1, 2, 3
*/

#include<iostream>
#include<vector>
using namespace std;

void printSubsets(vector<int>& arr, vector<int>& subset, int index) {
    if(index == arr.size()) {
        if(!subset.empty()) {
            for(int i = 0; i < subset.size(); i++) {
                cout << subset[i];
            }
            cout <<endl;
        }
        return;
    }

    // Include the current element in the subset
    subset.push_back(arr[index]);
    printSubsets(arr, subset, index + 1);

    subset.pop_back(); // Backtrack

    // Exclude the current element from the subset
    printSubsets(arr, subset, index + 1);
}

int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    vector<int> subset;
    cout<<"All subsets are: "<<endl;
    printSubsets(arr, subset, 0);

    return 0;
}

