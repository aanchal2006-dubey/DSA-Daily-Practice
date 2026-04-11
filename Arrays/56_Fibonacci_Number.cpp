/* The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is, F(0) = 0, F(1) = 1, and F(n) = F(n - 1) + F(n - 2) for n > 1. 

Input: n = 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.

Input: n = 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.
*/

#include<iostream>
using namespace std;

class Solution {
public: 
    int fib(int n) {
        if(n == 0 || n == 1) {
            return n;
        }
        return fib(n - 1) + fib(n - 2);
    }
};

int main() {
    int n;
    cout<<"Enter the value of n: ";
    cin>>n;
    
    Solution sol;
    int result = sol.fib(n);

    cout<<"The "<<n<<"th Fibonacci number is: "<<result<<endl;

    return 0;
}