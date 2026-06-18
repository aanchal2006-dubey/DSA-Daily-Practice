/* You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Input: coins = [1, 2, 5], amount = 11
Output: 3
Explanation: The minimum number of coins needed to make up the amount 11 is 3 (5 + 5 + 1).

Input: coins = [2], amount = 3
Output: -1
Explanation: The amount 3 cannot be made up by any combination of the coins.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for(int i=1; i<=amount; i++) {
            for(int j=0; j<coins.size(); j++) {
                if(coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

int main() {
    int n, amount;
    cout << "Enter the number of coin denominations: ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter the coin denominations: ";
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    cout << "Enter the amount: ";
    cin >> amount;

    Solution solution;
    int result = solution.coinChange(coins, amount);

    if(result == -1) {
        cout << "The amount cannot be made up by any combination of the coins." << endl;
    } else {
        cout << "The minimum number of coins needed: " << result << endl;
    }

    return 0;
}