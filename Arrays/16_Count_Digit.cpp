/* Given a positive integer n, count the number of digits in n that divide n evenly (i.e. without leaving a remainder). Return the total number of such digits.

A digit d of n divides n evenly if the remainder of n divided by d is 0 (n%d == 0). Digits of n should be checked individually. If a digit is 0, it should be ignored because division by 0 is undefined.

Input: n = 12
Output: 2
Explanation: 1, 2 when both divide 12 leaves remainder 0.

Input: n = 2446
Output: 1
Explanation: Here among 2, 4, 6 only 2 divides 2446evenly while 4 and 6 do not.
*/

#include<iostream>
#include<string>
using namespace std;

int evenlyDivides(int n){
    int count = 0;
    int temp = n;

    while(temp > 0){
        int digit = temp % 10;
        temp /= 10;

        if(digit > 0 && n % digit == 0){
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cout<<"Enter the positive integer: ";
    cin>>n;

    int result = evenlyDivides(n);
    cout<<result<<endl;

    return 0;
}