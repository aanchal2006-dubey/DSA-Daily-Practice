/* Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1. 

Input: s = "leetcode"
Output: 0
Explanation: The character 'l' at index 0 is the first character that does not occur at any other index.

Input: s = "loveleetcode"
Output: 2

Input: s = "aabb"
Output: -1
*/

#include<iostream>
#include<string>
#include<map>
#include<queue>
using namespace std;

class Solution {
public: 
    int firstUniqChar(string s) {
        map<char, int> charCount;
        queue<int> charIndex;
        
        for(int i = 0; i < s.length(); i++) {
            char c = s[i];
            charCount[c]++;
            if(charCount[c] == 1) {
                charIndex.push(i);
            }
        }
        
        while(!charIndex.empty()) {
            int index = charIndex.front();
            char c = s[index];
            if(charCount[c] == 1) {
                return index;
            }
            charIndex.pop();
        }
        
        return -1;
    }
};

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    Solution solution;
    int result = solution.firstUniqChar(s);

    if(result != -1) {
        cout << "The index of the first unique character is: " << result << endl;
    } else {
        cout << "There is no unique character in the string." << endl;
    }

    return 0;
}