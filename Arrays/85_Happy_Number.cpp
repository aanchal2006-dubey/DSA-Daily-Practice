/* Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process :
    - Starting with any positive integer, replace the number by the sum of the squares of its digits.
    - Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
    - Those numbers for which this process ends in 1 are happy.

Return true if n is a happy number, and false if not.

Input: n = 19
Output: true
Explanation:
    1^2 + 9^2 = 82
    8^2 + 2^2 = 68
    6^2 + 8^2 = 100
    1^2 + 0^2 + 0^2 = 1

Input: n = 2
Output: false
*/

#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> seen;

        while(n != 1 && seen.find(n) == seen.end()) {
            seen.insert(n);
            n = getSumOfSquares(n);
        }
        return n == 1;
    }

    int getSumOfSquares(int n) {
        int sum = 0;
        while(n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};

int main() {
    int n;
    cout<<"Enter a number: ";
    cin>>n;

    Solution sol;
    if(sol.isHappy(n)) {
        cout<<n<<" is a happy number."<<endl;
    } else {
        cout<<n<<" is not a happy number."<<endl;
    }

    return 0;
}