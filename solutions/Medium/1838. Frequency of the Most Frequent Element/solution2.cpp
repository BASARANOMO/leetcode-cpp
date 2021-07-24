#include <vector>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> preSum(n);
        preSum[0] = nums[0];
        for (int i = 1; i < n; i++) preSum[i] = preSum[i - 1] + nums[i];
        int res = 0;
        for (int i = 0; i < n; i++) {
            int left = 0, right = i, mid, temp = -1;
            while (left <= right) {
                mid = (left + right) / 2;
                if (nums[i] * (long long)(i - mid + 1) - preSum[i] + (mid > 0 ? preSum[mid - 1] : 0) <= k) {
                    right = mid - 1;
                    temp = mid;
                } else left = mid + 1;
            }
            if (temp != -1) res = max(res, i - temp + 1);
        }
        return res;
    }
};