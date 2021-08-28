#include <vector>
using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        vector<int> nums {0, 1};
        int ans = 1, curr;
        for (int i = 2; i < n + 1; i++) {
            if ((i & 1) == 0) curr = nums[i / 2];
            else curr = nums[i / 2] + nums[i / 2 + 1];
            ans = curr > ans ? curr : ans;
            nums.push_back(curr);
        }
        return ans;
    }
};