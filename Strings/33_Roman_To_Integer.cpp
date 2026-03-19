/* Input: s = "III"
Output: 3

Input: s = "LVIII"
Output: 58
*/

#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int result = 0;
        for(int i=0; i<s.size(); i++) {
            if(i+1 < s.size() && romanMap[s[i]] < romanMap[s[i+1]]) {
                result += romanMap[s[i+1]] - romanMap[s[i]];
                i++;
            }
            else {
                result += romanMap[s[i]];
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    string s;
    cout<<"Enter the Roman Number: ";
    cin>>s;

    int result = sol.romanToInt(s);

    cout<<s<<": "<<result<<endl;

    return 0;
}