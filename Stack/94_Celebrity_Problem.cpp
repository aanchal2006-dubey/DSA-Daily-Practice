/* Given a 2D array (n*n), such that arr[i][j]= 1 means its person knows jth person, the task is to find the celebrity.

A celebrity is a person who is known to all but does not know anyone.

Return the index of the celebrity, if there is no celebrity, return -1.

Input: arr = [[0,1,0],[0,0,0],[0,1,0]]
Output: 1
*/

#include <bits/stdc++.h>
using namespace std;

int findCelebrity(vector<vector<int>>& arr) {
    int n = arr.size();
    stack<int> s;
    
    for(int i=0; i<n; i++){
        s.push(i);
    }
    
    while(s.size() > 1){
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        
        if(arr[a][b] == 1){
            s.push(b);
        } else {
            s.push(a);
        }
    }
    
    int candidate = s.top();
    
    for(int i=0; i<n; i++){
        if(i != candidate){
            if(arr[candidate][i] == 1 || arr[i][candidate] == 0){
                return -1;
            }
        }
    }
    
    return candidate;
}

int main() {
    vector<vector<int>> arr = {{0,1,0},{0,0,0},{0,1,0}};
    cout << findCelebrity(arr) << endl; // Output: 1
    return 0;
}