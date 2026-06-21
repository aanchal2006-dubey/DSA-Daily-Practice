/* Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:
1. Insert a character
2. Delete a character
3. Replace a character

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (delete 'r')
rose -> ros (delete 'e')

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> exention (replace 'i' with 'e')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

class Solution {
public: 
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int> > dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i <= m; ++i) dp[i][0] = i;
        for (int j = 0; j <= n; ++j) dp[0][j] = j;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};

int minDistanceOptimized(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<int> dp(n+1, 0);
    for (int j = 0; j <= n; ++j) dp[j] = j;
    for (int i = 1; i <= m; ++i) {
        int prev = dp[0];
        dp[0] = i;
        for (int j = 1; j <= n; ++j) {
            int temp = dp[j];
            if (word1[i-1] == word2[j-1]) {
                dp[j] = prev;
            } else {
                dp[j] = min(prev, min(dp[j], dp[j-1])) + 1;
            }
            prev = temp;
        }
    }
    return dp[n];
}

int main() {
    string word1, word2;
    cout<<"Enter the first word: ";
    cin>>word1;
    cout<<"Enter the second word: ";
    cin>>word2;

    Solution sol;
    int result = sol.minDistance(word1, word2);
    cout<<"Minimum edit distance: "<<result<<endl;

    int optimizedResult = minDistanceOptimized(word1, word2);
    cout<<"Minimum edit distance (optimized): "<<optimizedResult<<endl;

    return 0;
}