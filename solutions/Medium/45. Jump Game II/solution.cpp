class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int maxPos = 0, end = 0;
        for (int i = 0; i < n - 1; i++) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
            }
            if (i == end) {
                end = maxPos;
                ans++;
            }
        }
        return ans;
    }
};