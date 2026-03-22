/*Given a 3-digit number n, find whether it is an armstrong number or not.

Input: n = 153
Output: true
*/

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

class Solution {
public:
    bool armstronNumber(int n){
        int copyN = n;
        int sumOfDigit = 0;

        if(n < 0){
            return 0;
        }

        int temp = n;
        int num = to_string(n).length();

        while(temp != 0){
            int digit = temp%10;
            sumOfDigit += round(pow(digit, num));
            temp /= 10;
        }
        return sumOfDigit == copyN;
    }
};

int main() {
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    Solution sol;
    bool result = sol.armstronNumber(n);

    cout<<result<<endl;

    return 0;
}