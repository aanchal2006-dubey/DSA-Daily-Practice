/* Given a signed 32-bit integer x, return x with its digits reversed. If reversing x cause the value to go outside the signed 32-bit integer range [-2^31, 2^31-1], then return 0:

Assume the environment does not allow you to store 64-bit integer (signed or unsigned).

Input: x = 123
output: 321

Input x = -123
Output: -321

Input: x = 120
Output: 21
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int revNum = 0;

        while(x != 0) {
            int digit = x%10;
            if(revNum > INT16_MAX/10 || revNum < INT16_MIN/10) {
                return 0;
            }
            revNum = (revNum*10) + digit;
            x = x/10;
        }
        return revNum;
    }
};

int main() {
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    Solution sol;
    int result = sol.reverse(n);

    cout<<"The reverse of "<<n<<" : "<<result<<endl;

    return 0;
}