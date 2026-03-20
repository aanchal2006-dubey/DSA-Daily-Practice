/* Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars: 
    - If the group's length is 1, append character to s.
    - Otherwise, append the character followed by the group's length.
    
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only contant extra space.

Input: chars = ["a", "a", "b", "b", "b", "c", "c", "c"]
Output: 6 --> The first 6 characters of input array should be : ["a", "2", "b", "3", "c", "3"]
Explaination: The groups are "aa", "bbb", and "ccc". This compresses to "a2b3c3"
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;

        for(int i = 0; i < n; i++) {
            char ch = chars[i];
            int count = 0;

            while(i < n && chars[i] == ch) {
                count++;
                i++;
            }

            chars[idx++] = ch;

            if(count > 1) {
                string str = to_string(count);
                for(char dig : str) {
                    chars[idx++] = dig;
                }
            }

            i--; 
        }

        chars.resize(idx);
        return idx;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<char> chars(n);

    cout << "Enter characters (space separated): ";
    for(int i = 0; i < n; i++) {
        cin >> chars[i];
    }

    Solution sol;
    int newLength = sol.compress(chars);

    cout << "Compressed Length: " << newLength << endl;

    cout << "Compressed Array: ";
    for(int i = 0; i < newLength; i++) {
        cout << chars[i] << " ";
    }
    cout << endl;

    return 0;
}