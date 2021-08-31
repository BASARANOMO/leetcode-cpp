#include <vector>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> diff(limit * 2 + 2, 0);
        int n = nums.size();
        int val1, val2, ans = n;
        for (int i = 0; i < n / 2; i++) {
            val1 = nums[i], val2 = nums[n - i - 1];
            diff[2] += 2, diff[limit * 2 + 1] -= 2;
            diff[1 + min(val1, val2)] -= 1, diff[limit + max(val1, val2) + 1] += 1;
            diff[val1 + val2] -= 1, diff[val1 + val2 + 1] += 1;
        }
        for (int i = 2; i < limit * 2 + 1; i++) {
            diff[i] += diff[i - 1];
            ans = ans > diff[i] ? diff[i] : ans;
        }
        return ans;
    }
};