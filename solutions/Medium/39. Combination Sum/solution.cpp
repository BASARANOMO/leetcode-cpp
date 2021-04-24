#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> res;
    vector<int> current;
    int n;
public:
    void backtracking(vector<int>& candidates, int target, int pos, int val) {
        if (target == val) {
            res.push_back(current);
            return;
        }
        if (pos == n || val > target) return;
        backtracking(candidates, target, pos + 1, val);
        current.push_back(candidates[pos]);
        backtracking(candidates, target, pos, val + candidates[pos]);
        current.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        backtracking(candidates, target, 0, 0);
        return res;
    }
};
