/* You are given two arrays a[], and b[], return the union of both the arrays in any order.

The union of two arrays is a collection of all distinct elements present in either of the arrays. If an element appears more than once in one or both arrays, it should be included only once in the result.

Print the result in sorted order only.

Input: a[] = [1, 2, 3, 2, 1], b[] = [3, 2, 2, 3, 3, 2]
Output: [1, 2, 3]
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public: 
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        set<int> unionSet;

        for(int num : a){
            unionSet.insert(num);
        }

        for(int num : b){
            unionSet.insert(num);
        }

        vector<int> result(unionSet.begin(), unionSet.end());
        return result;
    }  
};

int main(){
    int n, m;
    cout<<"Enter the size of both array: ";
    cin>>n>>m;

    cout<<"Enter the elements of both array : ";
    vector<int> a(n), b(m);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int j=0; j<m; j++){
        cin>>b[j];
    }

    Solution sol;
    vector<int> result = sol.findUnion(a, b);

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