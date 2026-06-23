/* Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

Input: s = "leetcode", wordDict = ["leet", "code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Input: s = "applepenapple", wordDict = ["apple", "pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".

Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
Output: false   
*/

#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};

int main() {
    string s;
    int n;
    cout << "Enter the string: ";
    cin >> s;

    cout << "Enter the number of words in the dictionary: ";
    cin >> n;

    vector<string> wordDict(n);
    cout << "Enter the words in the dictionary: ";
    for (int i = 0; i < n; ++i) {
        cin >> wordDict[i];
    }

    Solution solution;
    if (solution.wordBreak(s, wordDict)) {
        cout << "The string can be segmented into a space-separated sequence of one or more dictionary words." << endl;
    } else {
        cout << "The string cannot be segmented into a space-separated sequence of one or more dictionary words." << endl;
    }

    return 0;
}