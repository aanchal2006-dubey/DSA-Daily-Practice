/* There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to the next (i+1)th station. You begin the journey with an empty tank at one of the gas stations.

Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique. 

Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation: Start at station 3 (index 3) and fill up the tank with 4 units of gas. Travel to station 4 (index 4), spending 1 unit of gas and having 3 units left. Travel to station 0 (index 0), spending 5 units of gas and having -2 units left. Since we cannot travel further, return -1.
Therefore the starting station is 3.

Input: gas = [2,3,4], cost = [3,4,3]
Output: -1
Explanation: You can't start at station 0 or 1, as there is not enough gas to travel to the next station. Let's start at station 2 and fill up the tank with 4 units of gas. Travel to station 0, spending 3 units of gas and having 1 unit left. Travel to station 1, spending 4 units of gas and having -3 units left. Since we cannot travel further, return -1.
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = 0, total_cost = 0, current_gas = 0, start_station = 0;
        for (int i = 0; i < gas.size(); i++) {
            total_gas += gas[i];
            total_cost += cost[i];
            current_gas += gas[i] - cost[i];
            // if current_gas is negative, we cannot start from the previous station
            if (current_gas < 0) {
                start_station = i + 1; // move to the next station
                current_gas = 0; // reset current_gas for the new starting point
            }
        }
        return total_gas >= total_cost ? start_station : -1; // check if the total gas is enough to cover the total cost
    }
};

int main() {
    int n;
    cout<<"Enter the number of gas stations: ";
    cin>>n;

    vector<int> gas(n), cost(n);

    cout<<"Enter the amount of gas at each station: ";
    for (int i = 0; i < n; i++) {
        cin>>gas[i];
    }

    cout<<"Enter the cost of gas to travel to the next station: ";
    for (int i = 0; i < n; i++) {
        cin>>cost[i];
    }

    Solution solution;
    int result = solution.canCompleteCircuit(gas, cost);

    if (result != -1) {
        cout<<"You can start at station index: "<<result<<endl;
    } else {
        cout<<"You cannot complete the circuit from any station."<<endl;
    }

    return 0;
}