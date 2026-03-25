/* Given an integer x, return true if x is a palindrome, and false otherwise.

Input: x = 121
Output: true

Input: x = -121
Output: false

Input: x = 10
Output: false
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int n) {
        int revNum = 0;
        while(n != 0) {
            int digit = n%10;
            if(revNum > INT16_MAX/10 || revNum < INT16_MIN/10) {
                return 0;
            }
            revNum = (revNum*10) + digit;
            n = n/10;
        }
        return revNum;
    }

    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }
        int revNum = reverse(x);
        return x == revNum;
    }
};

int main() {
    int x;
    cout<<"Enter the value of x: ";
    cin>>x;

    Solution sol;
    int result = sol.isPalindrome(x);

    cout<<result<<endl;

    return 0;
}