/* Given two strings s1 and s2, return the length of their longest common subsequence.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements. 

For example, "ace" is a subsequence of "abcde". 

Input Format:
    The first line contains two integers n and m: lengths of the two strings.
    The second line contains the string s1.
    The third line contains the string s2.

Output Format:
    Print a single integer: the length of the longest common subsequence.

Example Input:
    5 3
    abcde
    ace

Example Output:
    3

Explanation: The longest common subsequence is "ace" with length 3.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int lcs(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    
    // Create a 2D DP array to store the lengths of longest common subsequences
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The length of the longest common subsequence will be in the bottom-right cell of the DP table
    return dp[n][m];
}

int lcsOptimized(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();
    
    // Create a 1D DP array to store the lengths of longest common subsequences
    vector<int> dp(m + 1, 0);

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        vector<int> prev(dp);
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[j] = prev[j - 1] + 1;
            } else {
                dp[j] = max(prev[j], dp[j - 1]);
            }
        }
    }

    // The length of the longest common subsequence will be in the last cell of the DP array
    return dp[m];
}

int main() {
    int n, m;
    cout << "Enter lengths of the two strings: ";
    cin >> n >> m;

    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    int length = lcs(s1, s2);
    cout << "Length of Longest Common Subsequence: " << length << endl;

    return 0;
}