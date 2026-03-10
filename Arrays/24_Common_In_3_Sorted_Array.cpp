/* Given three sorted arrays in non-decreasing order print all common elements in non-decreasing order across these arrays. If there are no such elements return an empty array. In this case, the output will be -1.

Node: Can you handle the duplicates without using any additional data structure?

Input: arr1 = [1, 5, 10, 20, 40, 80], arr2 = [6, 7, 20, 80, 100], arr3 = [3, 4, 15, 20, 30, 70, 80]
Output: [20, 80]
Explaination: 20 and 80 are the only common elements in arr1, arr2, arr3.

Input: arr1 = [1, 2, 3, 4, 5], arr2 = [6, 7], arr3 = [8, 9, 10]
Output: [-1]
Explaination: There are no common elements in arr1, arr2, arr3.

Input: arr1 = [1, 1, 1, 2, 2, 2], arr2 = [1, 1, 2, 2, 2], arr3 = [1, 1, 1, 1, 2, 2, 2]
Output: [1, 2]
Explaination: We do not need to consider duplicates.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public: 
    vector<int> commonElements(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
        int i=0, j=0, k=0;
        int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();
        vector<int> common;

        while(i<n1 && j<n2 && k<n3){
            if(arr1[i] == arr2[j] && arr2[j] == arr3[k]){
                common.push_back(arr1[i]);
                i++;
                j++;
                k++;

                while(i<n1 && arr1[i] == arr1[i-1])
                    i++;
                while(j<n2 && arr2[j] == arr2[j-1])
                    j++;
                while(k<n3 && arr3[k] == arr3[k-1])
                    k++;
            }
            else if(arr1[i] < arr2[j])
                i++;
            else if(arr2[j] < arr3[k])
                j++;
            else
                k++;
        }
        return common;
    }
};

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    vector<int> arr1(n1), arr2(n2), arr3(n3);

    for(int i=0; i<n1; i++)
        cin >> arr1[i];
    for(int i=0; i<n2; i++)
        cin >> arr2[i];
    for(int i=0; i<n3; i++)
        cin >> arr3[i];

    Solution sol;
    vector<int> result = sol.commonElements(arr1, arr2, arr3);

    if(result.empty()){
        cout << -1 <<endl;
    }
    else{
        for(int i=0; i<result.size(); i++){
            cout << result[i] <<" ";
        }
        cout << endl;
    }

    return 0;
}