/* You are thief with a knapsack that can carry a maximum weight of W. There are n items. Each item has a weight w[i] and a value v[i].

You can either take an item completely or leave it. You cannot take a fraction of an item.

Find the maximum total value you can put in the knapsack.

Input Format:
    The first line contains two integers n and W: number of items and knapsack capacity.
    The second line contains n integers: weights of items W[1]...W[n].
    The third line contains n integers: values of items v[1]...v[n].
    
Output Format:
    Print a single integer: the maximum value that can be obtained.
    
Example Input:
    4 7
    1 3 4 5
    1 4 5 7
Example Output:
    9

Explanation: Take items with weights 3 and 4. Total weight = 3 + 4 = 7, total value = 4 + 5 = 9. This is optimal.
*/  

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int knapsack(int W, vector<int>& weights, vector<int>& values, int n) {
    // Create a 2D DP array to store the maximum value at each n and W
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value will be in the bottom-right cell of the DP table
    return dp[n][W];
}

int knapsackOptimized(int W, vector<int>& weights, vector<int>& values, int n) {
    // Create a 1D DP array to store the maximum value at each W
    vector<int> dp(W + 1, 0);

    // Build the DP table
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }

    // The maximum value will be in the last cell of the DP array
    return dp[W];
}

int main() {
    int n, W;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> W;

    vector<int> weights(n);
    vector<int> values(n);

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    // Call the knapsack function
    int maxValue = knapsackOptimized(W, weights, values, n);
    
    cout << maxValue << endl;

    return 0;
}