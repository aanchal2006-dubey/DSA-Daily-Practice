/* Write a function that reverses a string. The input string is given as an array of characters.

You must do this by modifying the input array in-place with 0(1) extra memory.

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};

int main() {
    int n;
    cout<<"Enter the number of characters in the string: ";
    cin>>n;

    vector<char> s(n);
    cout<<"Enter the characters of the string: ";
    for(int i = 0; i< n; i++) {
        cin>>s[i];
    }

    Solution solution;
    solution.reverseString(s);

    cout<<"Reversed String: ";
    for(int i = 0; i < n; i++) {
        cout<<s[i]<<" ";
    }
    cout<<endl;

    return 0;
}