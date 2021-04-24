#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        // dynamic programming to find the size of the largest divisible set
        vector<int> dp(n, 1);
        int maxSize = 1;
        int maxVal = nums[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) dp[i] = max(dp[j] + 1, dp[i]);
            }
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxVal = nums[i];
            }
        }

        // to find the set
        vector<int> res;
        
        if (maxSize == 1) {
            res.push_back(nums[0]);
            return res;
        }
        for (int i = n - 1; i >= 0 && maxSize > 0; i--) {
            if (dp[i] == maxSize && maxVal % nums[i] == 0) {
                res.push_back(nums[i]);
                maxSize--;
                maxVal = nums[i];
            }
        }
        return res;
    }
};