/* Given an integer n, return the number of prime numbers that are strictly less than n.

Input: n = 10
Output: 4
Explanation: 2, 3, 5, 7

Input: n = 0
Output: 0

Input: n = 1
Output: 0
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countPrimes (int n) {
        vector<bool> isPrime(n+1, true);
        int ans = 0;

        for(int i=2; i<n; i++) {
            if(isPrime[i]){
                ans++;
                for(int j=i*2; j<n; j=j+i){
                    isPrime[j] = false;
                }
            }
        }
        return ans;
    }
};

int main(){
    int n;
    cout<<"Enter value of n: ";
    cin>>n;

    Solution sol;
    int result = sol.countPrimes(n);

    cout<<result<<endl;

    return 0;
}