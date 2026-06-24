/* You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like with the following restrictions:
    1. After you sell your stock, you cannot buy stock on the next day (i.e., cooldown 1 day).
    2. You may not engage in multiple transactions simultaneously (i.e., you must sell before you buy again).
    
Example 1:
Input: prices = [1][2][3][0][2]
Output: 3
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;

        vector<int> hold(n, 0), sold(n, 0), rest(n, 0);

        hold[0] = -prices[0];
        sold[0] = 0;
        rest[0] = 0;

        for(int i=1; i<n; i++) {
            hold[i] = max(hold[i-1], rest[i-1] - prices[i]);
            sold[i] = hold[i-1] + prices[i];
            rest[i] = max(rest[i-1], sold[i-1]);
        }

        return max(sold[n-1], rest[n-1]);
    }
};

int main() {
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    vector<int> prices(n);
    cout<<"Enter Prices : "<<endl;
    for(int i=0; i<n; i++) {
        cin>>prices[i];
    }

    Solution sol;
    int result = sol.maxProfit(prices);
    
    cout<<"Max profit : "<<result<<endl;

    return 0;
}