class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (auto num : nums) sum += num;
        // 0-1 knapsack
        if (sum & 1) return false;
        int target = sum / 2;
        vector<vector<int> > dp_matrix(n + 1, vector<int>(target + 1, 0));
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < target + 1; j++) {
                if (j - nums[i-1] < 0) dp_matrix[i][j] = dp_matrix[i-1][j];
                else {
                    dp_matrix[i][j] = max(dp_matrix[i-1][j], dp_matrix[i-1][j - nums[i-1]] + nums[i-1]);
                }
            }
        }
        return dp_matrix[n][target] == target;
    }
};
