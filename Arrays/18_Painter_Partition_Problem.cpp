/* Given arr N boards of length of each given in the form of array, and M painters, such that each painter takes 1 unit of time to paint 1 unit of the board.

The task is to find the minimum time to paint all boards under the constraints that any painter will only paint continuous sections of boards.

Input: arr = [40, 30, 10, 20], N = 4, M = 2
Output: 60
Explanation: One optimal way is:
- Painter 1 paints boards [40, 30] (total time = 70)
- Painter 2 paints boards [10, 20] (total time = 30)
The maximum time taken by any painter is 70. But we want to minimize the maximum time.
So, we try to distribute the boards more evenly:
- Painter 1 paints boards [40, 10] (total time = 50)
- Painter 2 paints boards [30, 20] (total time = 50)
The maximum time is now minimized to 50. But this is not the optimal solution.
The optimal solution is:
- Painter 1 paints boards [40] (total time = 40)
- Painter 2 paints boards [30, 10, 20] (total time = 60)
The maximum time is now minimized to 60.
*/
#include<iostream>
#include<vector>
using namespace std;

int isPossible(vector<int> &arr, int n, int m, int maxAllowedTime){
    int paintersRequired = 1;
    int currentTime = 0;

    for(int i=0; i<n; i++){
        if(currentTime + arr[i] <=maxAllowedTime){
            currentTime += arr[i];
        }
        else{
            paintersRequired++;
            currentTime = arr[i];
        }
    }
    return paintersRequired <= m;
}

int minTimeToPaint(vector<int> &arr, int n, int m){
    int sum = 0, maxVal = 0;

    for(int i=0; i<n; i++){
        sum += arr[i];
        maxVal = max(maxVal, arr[i]);
    }

    int st = maxVal, end = sum, ans = -1;

    while(st <= end){
        int mid = st + (end-st)/2;

        if(isPossible(arr, n, m, mid)){
            ans = mid;
            end = mid - 1;
        }
        else{
            st = mid + 1;
        }
    }
    return ans;
}

int main(){
    int n, m;
    cout<<"Enter the number of boards: ";
    cin>>n>>m;

    vector<int> arr(n);
    cout<<"Enter the lengths of the boards: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int result = minTimeToPaint(arr, n, m);
    cout<<"Minimum time to paint all boards: "<<result<<endl;

    return 0;
}