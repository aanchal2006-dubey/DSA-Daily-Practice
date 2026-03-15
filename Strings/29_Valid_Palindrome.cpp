/* A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, if reads the same forward and backward.

Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome or false otherwise.

Input: s = "A man, a plan, a canal: panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isAlphanumeric(char ch) {
        if((ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z')) {
            return true;
        }   
        return false;
    }

    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while(left < right) { 
            if(!isAlphanumeric(s[left])) {
                left++; continue;
            }
            if(!isAlphanumeric(s[right])) {
                right--; continue;
            }
            if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++; right--;
        }
        return true;
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    bool result = sol.isPalindrome(s);

    if(result) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}