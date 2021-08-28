#include <vector>
using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        vector<int> nums(n + 1);
        nums[1] = 1;
        int ans = 1, curr;
        for (int i = 2; i < n + 1; i++) {
            curr = nums[i / 2] + (i % 2) * nums[i / 2 + 1];
            ans = curr > ans ? curr : ans;
            nums[i] = curr;
        }
        return ans;
    }
};