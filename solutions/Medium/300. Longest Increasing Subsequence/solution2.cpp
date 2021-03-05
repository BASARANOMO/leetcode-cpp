class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), len = 1;
        vector<int> minIdxForLen(n, 0);
        minIdxForLen[0] = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > minIdxForLen[len - 1]) {
                minIdxForLen[len++] = nums[i];
            } else {
                int left = 1, right = len, pos = 0, mid;
                while (left <= right) {
                    mid = (left + right) / 2;
                    if (minIdxForLen[mid - 1] < nums[i]) {
                        pos = mid;
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                minIdxForLen[pos] = nums[i];
            }
        }
        return len;
    }
};
