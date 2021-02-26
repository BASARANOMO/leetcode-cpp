class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // write your code in C++14 (g++ 6.2.0)
        int n = nums.size();
        vector<bool> exist(n, false);
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0 && nums[i] <= n) exist[nums[i] - 1] = true;
        }
        for (int i = 0; i < n; i++) {
            if (!exist[i]) return i + 1;
        }
        return n + 1;
    }
};
