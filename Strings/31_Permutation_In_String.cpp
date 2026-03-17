/* Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explaination: s2 contains one permutation of s1 ("ba")

Input: s1 = "ab", s2 = "eidboaoo"
Output: false
Explaination: s2 does not contain any permutation of s1.

s1 and s2 consist of lowercase english letters.
*/

#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    
    if (n1 > n2) return false;

    vector<int> count1(26, 0), count2(26, 0);

    // Frequency of s1
    for (int i = 0; i < s1.size(); i++) {
    count1[s1[i] - 'a']++;
    }

    // First window
    for (int i = 0; i < n1; i++) {
        count2[s2[i] - 'a']++;
    }

    if (count1 == count2) return true;

    // Sliding window
    for (int i = n1; i < n2; i++) {
        count2[s2[i] - 'a']++;           // add new char
        count2[s2[i - n1] - 'a']--;      // remove old char

        if (count1 == count2) return true;
    }

    return false;
}

int main() {
    string s1 = "ab", s2 = "eidbaooo";

    if (checkInclusion(s1, s2))
        cout << "true";
    else
        cout << "false";

    return 0;
}