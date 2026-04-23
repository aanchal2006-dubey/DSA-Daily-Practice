/* Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Input: s = "aab"
Output: [["a", "a", "b"], ["aa", "b"]]

Input: s = "a"
Output[["a"]]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isPalin(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());

        return s == s2;
    }

    void getAllParts(string s, vector<string>& partitions, vector<vector<string> >& ans) {
        if(s.size() == 0) {
            ans.push_back(partitions);
            return;
        }

        for(int i=0; i<s.size(); i++) {
            string parts = s.substr(0, i+1);

            if(isPalin(parts)) {
                partitions.push_back(parts);
                getAllParts(s.substr(i+1), partitions, ans);
                partitions.pop_back();
            }
        }
    }

    vector<vector<string> > partition(string s) {
        vector<vector<string> > ans;
        vector<string> partitions;

        getAllParts(s, partitions, ans);

        return ans;
    }
};

int main() {
    Solution sol;
    string input;

    cout << "Enter a string: ";
    cin >> input;

    vector<vector<string> > result = sol.partition(input);

    cout << "Possible palindrome partitions:" << endl;
    
    // Outer loop to iterate through each partition set
    for (int i = 0; i < result.size(); i++) {
        cout << "[ ";
        // Inner loop to iterate through strings within a partition
        for (int j = 0; j < result[i].size(); j++) {
            cout << "\"" << result[i][j] << "\" ";
        }
        cout << "]" << endl;
    }

    return 0;
}