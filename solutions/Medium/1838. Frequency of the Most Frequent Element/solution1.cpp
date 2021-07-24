#include <vector>
using namespace std;

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int left = 0, res = 1;
        long long total = 0;
        for (int right = 1; right < n; right++) {
            total += (long long)(nums[right] - nums[right - 1]) * (right - left);
            while (total > k) {
                total -= (nums[right] - nums[left]);
                left++;
            }
            res = max(right - left + 1, res);
        }
        return res;
    }
};