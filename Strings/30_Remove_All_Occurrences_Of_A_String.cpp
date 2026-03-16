/* Given two string s and part, perform the following operation on s until all occurrences of the substring part are removed.

Find the leftmost occurrence of the substring part and remove it from s.

Return s after removing all occurrences of part.

A substring is a contiguous sequence of character in a string.

Input: s = "daabcbaabcbc", part = "abc"
Output: "dab"
Explaination: The following operation are done -
              s = "da'abc'baabcbc" remove "abc" starting at index 2, so s = "dabaabcbc"
              s = "daba'abc'bc" remove "abc" starting at index 4, so s = "dababc"
              s = "dab'abc'" remove "abc" starting at index 3, so s = "dab"
              Now, s has no occurrences of "abc"
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() > 0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }  
};

int main() {
    string s;
    cout<<"Enter the string: ";
    getline(cin, s);

    string part;
    cout<<"Enter part which you want to remove: ";
    getline(cin, part);

    Solution sol;
    string result = sol.removeOccurrences(s, part);

    cout<<result<<endl;

    return 0;
}