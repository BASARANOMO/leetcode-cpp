class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xorNum = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            xorNum ^= nums[i];
            xorNum ^= i;
        }
        xorNum ^= n;
        return xorNum;
    }
};