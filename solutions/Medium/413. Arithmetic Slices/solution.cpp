#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 0;
        int diff = nums[0] - nums[1], t = 0, res = 0;
        for (int i = 2; i < n; i++) {
            if (nums[i - 1] - nums[i] == diff) t++;
            else {
                diff = nums[i - 1] - nums[i];
                t = 0;
            }
            res += t;
        }
        return res;
    }
};
