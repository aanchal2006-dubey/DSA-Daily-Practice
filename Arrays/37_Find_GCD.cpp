/* Given two positive integers a and b, find GCD of a and b.
Note: Don't use the inbuilt gcd function.

Input: a = 20, b = 28
Output: 4
*/

#include<iostream>
using namespace std;

class Solution {
public:
    int gcd(int a, int b){
        while(a>0 && b>0){
            if(a>b){
                a = a%b;
            }
            else{
                b = b%a;
            }
        }
        if(a == 0){
            return b;
        }
        else{
            return a;
        }
    }
};

int main(){
    int a, b;
    cout<<"Enter the value of a and b: ";
    cin>>a>>b;

    Solution sol;
    int result = sol.gcd(a, b);

    cout<<"GCD of "<<a<<" and "<<b<<" : "<<result<<endl;

    return 0;
}