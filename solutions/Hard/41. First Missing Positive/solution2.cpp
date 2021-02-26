class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // write your code in C++14 (g++ 6.2.0)
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0) nums[i] = n + 1;
        }
        for (int i = 0; i < n; i++) {
            if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0) {
                nums[abs(nums[i]) - 1] = - nums[abs(nums[i]) - 1];
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) return i + 1;
        }
        return n + 1;
    }
};
