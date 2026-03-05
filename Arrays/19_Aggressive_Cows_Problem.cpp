/* Assign C cows to N stalls such that min distance between them is largest possible. Return largest minimum distance.

N = 5, arr = [1, 2, 4, 8, 4, 9], C = 3
Output: 3
Explanation: Place the 3 cows in 1st, 4th and 6th stalls. Minimum distance between cows is 3.
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> &stalls, int cows, int minDist){
    int count = 1; // Place the first cow in the first stall
    int lastPos = stalls[0];

    for(int i = 1; i < stalls.size(); i++){
        if(stalls[i] - lastPos >= minDist){
            count++;
            lastPos = stalls[i];
        }
        if(count >= cows) return true; // If we can place all cows with at least minDist
    }
    return false; // Not possible to place all cows with at least minDist
}

int aggressiveCows(vector<int> &stalls, int cows) {
    sort(stalls.begin(), stalls.end()); // Sort the stall positions
    int low = 1; // Minimum distance can be at least 1
    int high = stalls.back() - stalls[0]; // Maximum distance can be the distance between the farthest stalls
    int result = 0;

    while(low <= high){
        int mid = low + (high - low) / 2; // Mid distance to check

        if(isPossible(stalls, cows, mid)){
            result = mid; // Update result if it's possible to place cows with mid distance
            low = mid + 1; // Try for a larger distance
        } else {
            high = mid - 1; // Try for a smaller distance
        }
    }
    return result; // Largest minimum distance found
}

int main(){
    vector<int> stalls = {1, 2, 4, 8, 4, 9};
    int cows = 3;
    cout << aggressiveCows(stalls, cows) << endl; // Output: 3
    return 0;
}