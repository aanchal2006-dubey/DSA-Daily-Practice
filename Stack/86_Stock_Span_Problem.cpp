/* Stock Span Problem.

Input: The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains an integer N denoting the size of the array. The next line contains N space separated integers denoting the elements of the array.
Output: For each test case, print the span values of the array in a single line.

price = {100, 80, 60, 70, 60, 75, 85}
span = {1, 1, 1, 2, 1, 4, 6}
*/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> calculateSpan(vector<int>& price) {
        int n = price.size();
        vector<int> span(n);
        stack<int> s;

        for(int i = 0; i < n; i++) {
            while(!s.empty() && price[s.top()] <= price[i]) {
                s.pop();
            }
            span[i] = s.empty() ? (i + 1) : (i - s.top());
            s.push(i);
        }
        return span;
    }
};

int main() {
    int n;
    cout<<"Enter the number of days: ";
    cin>>n;

    vector<int> price(n);
    cout<<"Enter the stock prices: ";
    for(int i = 0; i < n; i++) {
        cin>>price[i];
    }

    Solution sol;
    vector<int> span = sol.calculateSpan(price);

    cout<<"Stock span values: ";
    for(int i = 0; i < n; i++) {
        cout<<span[i]<<" ";
    }

    return 0;
}