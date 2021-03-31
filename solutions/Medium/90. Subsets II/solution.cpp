class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtracking(false, 0, nums, res, curr);
        return res;
    }
    
    void backtracking(bool prev_chosen, int pos, vector<int>& nums, vector<vector<int>>& res, vector<int> curr) {
        if (pos == nums.size()) {
            res.push_back(curr);
            return;
        }
        backtracking(false, pos + 1, nums, res, curr);
        if (!prev_chosen && pos > 0 && nums[pos] == nums[pos - 1]) return;
        curr.push_back(nums[pos]);
        backtracking(true, pos + 1, nums, res, curr);
        curr.pop_back();
    }
};