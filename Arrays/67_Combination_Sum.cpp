/* Given an array of distinct integer candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen number is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Input: candidates = [2, 3, 6, 7], target = 7
Output: [[2, 2, 3],[7]]

Input: candidates = [2, 3, 5], target = 8
Output: [[2, 2, 2, 2], [2, 3, 3], [3, 5]]

Input: candidates = [2], target = 1
Output: []
*/

#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    set<vector<int> > s; //to store unique element

    void getAllCombinations(vector<int>& candidates, int idx, int target, vector<vector<int> >& ans, vector<int>& combin) {
        if(idx == candidates.size() || target < 0) {
            return;
        }
        if(target == 0) {
            if(s.find(combin) == s.end()) {
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }
        combin.push_back(candidates[idx]);

        //single
        getAllCombinations(candidates, idx+1, target-candidates[idx], ans, combin);

        //multiple
        getAllCombinations(candidates, idx, target-candidates[idx], ans, combin);

        combin.pop_back(); //backtracking

        //exclusion
        getAllCombinations(candidates, idx+1, target, ans, combin);
    }

    vector<vector<int> >combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > ans;
        vector<int> combin;

        getAllCombinations(candidates, 0, target, ans, combin);

        return ans;
    }
};

int main() {
    Solution sol;
    int n, target;

    cout << "Enter the number of candidates: ";
    cin >> n;

    vector<int> candidates(n);
    cout << "Enter the candidate integers: ";
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }

    cout << "Enter the target sum: ";
    cin >> target;

    vector<vector<int> > result = sol.combinationSum(candidates, target);

    cout << "\nUnique combinations that sum to " << target << ":" << endl;
    if (result.empty()) {
        cout << "[]" << endl;
    } else {
        cout << "[";
        for (int i = 0; i < result.size(); i++) {
            cout << "[";
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j];
                if (j < result[i].size() - 1) cout << ", ";
            }
            cout << "]";
            if (i < result.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}