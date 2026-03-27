/* Implement pow(x, n), which calculate x raised to the power n (i.e., x^n)

Input: x = 2.00000, n = 10
Output: 1024.00000

Input: x = 2.10000, n = 3
Output: 2.36100

Input: x = 2.00000, n = -2
Output: 0.2500
Explaination: 2^-2 = 1/2^2 = 1/4 = 0.25*/

#include<iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long binForm = n;
        double ans = 1;

        if(n == 0) 
            return 1.0;
        if(x == 0)
            return 0.0;
        if(x == 1) 
            return 1.0;
        if(x == -1 && n%2 == 0)
            return 1.0;
        if(x == -1 && n%2 != 0)
            return -1.0;

        if(n<0) {
            x = 1/x;
            binForm = -binForm;
        }

        while(binForm > 0) {
            if(binForm%2 == 1) {
                ans *= x;
            }
            x *= x;
            binForm/= 2;
        }
        return ans;
    }
};

int main() {
    double x, n;
    cout<<"Enter the value of x and n: ";
    cin>>x>>n;

    Solution sol;
    long long result = sol.myPow(x, n);

    cout<<x<<" raised to "<<n<<" : "<<result<<endl;

    return 0;
}