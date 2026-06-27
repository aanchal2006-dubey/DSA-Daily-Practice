/* Given a string s, return the number of palindromic substrings in it.

A string is a palindromic when it reads the same backward as forward.

A substring is a contiguous sequence of characters within the string.

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "aa", "aaa".
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public: 
    int countSubstrings_DP(string s) {
        int n = s.size();
        vector<vector<bool> > dp(n, vector<bool>(n, false));
        int count = 0;

        for(int i=0; i<n; i++) {
            dp[i][i] = true;
            count++;
        }

        for(int i=0; i<n-1; i++) {
            if(s[i] == s[i+1]) {
                dp[i][i+1] = true;
                count++;
            }
        }

        for(int len = 3; len <=n; len++) {
            for(int i=0; i<=n-len; i++) {
                int j = i + len - 1;
                if(s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    count++;
                }
            }
        }

        return count;
    }

    int countSubstrings(string s) {
        int n = s.size(), count = 0;

        for(int center=0; center<n; center++) {
            count += expand(s, center, center);
            count += expand(s, center, center + 1);
        }

        return count;
    }

    int expand(string& s, int left, int right) {
        int count = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }

        return count;
    }
};

int main() {
    string s;
    cout<<"Enter string : ";
    cin>>s;

    Solution sol;
    int result = sol.countSubstrings(s);

    cout<<"Palindromic Substrings : "<<result<<endl;

    return 0;
}
