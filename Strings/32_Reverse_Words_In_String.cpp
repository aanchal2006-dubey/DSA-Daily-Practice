/* Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. THe returned string should only have a single space separating the words. Do not include any extra spaces.

Input: s = "the sky is blue"
Output: "blue is sky the"

Input: s = " hello world "
Output: "world hello"
Explaination: Your reversed string should not contain leading or trailing spaces.

Input: s = "a good   example"
Output: "example good a"
Explaination: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());

        for(int i=0; i<n; i++) {
            string word = "";
            while(i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            reverse(word.begin(), word.end());

            if(word.length() > 0) {
                ans += " " + word;
            }
        }
        return ans.substr(1);
    }
};

int main() {
    string s;
    cout<<"Enter the string: ";
    getline(cin, s);

    Solution sol;
    string result = sol.reverseWords(s);

    cout<<result<<endl;
    
    return 0;
}