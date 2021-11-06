class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> idx(n + 1);
        for (int i = 0; i < n; i++) {
            idx[nums[i]] = 1;
        }
        for (int i = 0; i < n + 1; i++) {
            if (idx[i] == 0) return i;
        }
        return -1;
    }
};