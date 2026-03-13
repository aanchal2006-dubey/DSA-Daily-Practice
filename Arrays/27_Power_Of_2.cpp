/* Given a non-negative interger n. You have to check if it is a power of 2 or not.

Input: n = 8
Output: true
Explanation: 8 is equal to 2  raised to the power 2 (2^3 = 8)

input: n = 98
Output: false
Explanation: 98 is not equal to 2 raised to the power of any integer.

Input: n = 1
Output: true
Explanation: 1 is equal to 2 raised to the power 0 (2^0 = 1).
*/

#include<iostream>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }

        while(n > 1) {
            if (n % 2 != 0) {
                return false;
            }
            n /= 2;
        }
        return true;
    }
};

int main() {
    Solution sol;

    int n;
    cout<<"Enter a non-negative integer: ";
    cin>>n;

    if(sol.isPowerOfTwo(n)) {
        cout<<n<<" : true"<<endl;
    }
    else {
        cout<<n<<" : false"<<endl;
    }

    return 0;
}