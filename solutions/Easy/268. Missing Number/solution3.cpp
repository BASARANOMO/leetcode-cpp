class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int arrSum = 0, n = nums.size();
        for (int i = 0; i < n; i++) arrSum += nums[i];
        return (1 + n) * n / 2 - arrSum;
    }
};