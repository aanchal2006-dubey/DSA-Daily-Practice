/* Find the first non-repeating element in an array 

Input : n = 7
        arr[] = {4, 5, 1, 2, 0, 4, 1}
        Output : 5
Explanation : 5 is the first element in the array which is non-repeating.
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    map<int, int> freq;
    for(int i=0; i<n; i++){
        freq[arr[i]]++;
    }

    for(int i=0; i<n; i++){
        if(freq[arr[i]] == 1){
            cout<<"The first non-repeating element is: "<<arr[i]<<endl;
            return 0;
        }
    }

    cout<<"There is no non-repeating element in the array."<<endl;

    return 0;
}