/* Find all the duplicates from the given array.

Input: arr[2, 3, 1, 2, 3]
Output: [2, 3]*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    unordered_set<int> seen;
    vector<int> duplicates;

    for (int num : nums) {
        if (seen.count(num)) {
            duplicates.push_back(num);
        } else {
            seen.insert(num);
        }
    }

    return duplicates;
}

int main() {
    vector<int> arr = {2, 3, 1, 2, 3};
    vector<int> result = findDuplicates(arr);

    cout << "Duplicates: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}