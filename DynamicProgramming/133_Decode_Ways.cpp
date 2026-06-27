/* You have intercepted a secret message encoded as a string of numbers. The message was originally a string of uppercase letters where 'A' = "1", 'B' ="2",..., 'Z' = "26".

Given a string s containing only digits, return the number of ways to decode it.

Input: s = "12"
Output: 2
Explanation: "12" could be decoded as "AB" (1 2) or "L" (12).

Input: s = "226"
Output: 3
Explanation: "226" could be decoded as "BZ" (2 26), or "BBF" (2 2 6).
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0 || s[0] == '0') return 0;

        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2; i<=n; i++) {
            int oneDigit = s[i-1] - '0';
            if(oneDigit >= 1 && oneDigit <= 9) {
                dp[i] += dp[i-1];
            }

            int twoDigit = (s[i-2] - '0') * 10 + (s[i-1] - '0');
            if(twoDigit >= 10 && twoDigit <= 26) {
                dp[i] += dp[i-2];
            }
        }

        return dp[n];
    }
};

int main() {
    string s;
    cout<<"Enter the string : ";
    cin>>s;

    Solution sol;
    int result = sol.numDecodings(s);

    cout<<"Decode ways of "<<s<<" is : "<<result<<endl;

    return 0;
}