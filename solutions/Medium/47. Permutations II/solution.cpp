#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void backtracking(vector<int>& nums, int pos, unordered_map<int, int>& num_count, vector<int>& curr, vector<vector<int>>& res) {
        if (pos == nums.size()) {
            res.push_back(curr);
            return;
        }
        for(auto it = num_count.begin(); it != num_count.end(); it++) {
            if (it->second != 0) {
                curr[pos] = it->first;
                it->second -= 1;
                backtracking(nums, pos+1, num_count, curr, res);
                it->second += 1;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // backtracking
        vector<vector<int>> res;
        vector<int> curr(nums.size());
        unordered_map<int, int> num_count;
        for (int i = 0; i < nums.size(); i++) {
            if (num_count.find(nums[i]) == num_count.end()) num_count[nums[i]] = 1;
            else num_count[nums[i]] += 1;
        }
        backtracking(nums, 0, num_count, curr, res);
        return res;
    }
};

