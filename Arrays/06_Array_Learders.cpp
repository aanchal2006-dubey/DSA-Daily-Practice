/* Find all the array leaders in the given array.

Input: arr = [16, 17, 4, 3, 5, 2]
Output: [17, 5, 2]

Input: [10, 4, 2, 4, 1]
Output: [10, 4, 4, 1]*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> findLeaders(vector<int>& arr){
    vector<int> leaders;
    int n = arr.size();

    int maxRight = arr[n-1];
    leaders.push_back(maxRight);

    for(int i=n-2; i>=0; i--){
        if(arr[i] >= maxRight){
            maxRight = arr[i];
            leaders.push_back(maxRight);
        }
    }

    reverse(leaders.begin(), leaders.end());

    return leaders;
}

int main(){
    int n;
    cout<<"Enter the number of array element: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the array elements: ";

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    vector<int> leaders = findLeaders(arr);

    cout<<"Leaders in the array: ";
    for(int leader : leaders){
        cout<<leader<<" ";
    }
    cout<<endl;

    return 0;
}