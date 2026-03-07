/* Input: num = 3749 
Output: "MMMDCCXLIX"
Explanation: 3000 = MMM, 700 = DCC, 40 = XL and 9 = IX.

Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5 and III = 3.

Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num){
        vector<string> m = {"", "M", "MM", "MMM"};
        vector<string> c = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> x = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> i = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

        string thousands = m[num / 1000];
        string hundreds = c[(num % 1000) / 100];
        string tens = x[(num % 100) / 10];
        string ones = i[num % 10];

        string result = thousands + hundreds + tens + ones;

        return result;
    }
};

int main(){
    int num;
    cout<<"Enter an integer: ";
    cin>>num;

    Solution solutions;
    string romanNumeral = solutions.intToRoman(num);

    cout<<"Roman numeral: "<<romanNumeral<<endl;

    return 0;
}