class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int f = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            f += i * nums[i];
            sum += nums[i];
        }
        int ans = f;
        for (int i = 1; i < n; i++) {
            f = f + sum - n * nums[n - i];
            ans = max(ans, f);
        }
        return ans;
    }
};