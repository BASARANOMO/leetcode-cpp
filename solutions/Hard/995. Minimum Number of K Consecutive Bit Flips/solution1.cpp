#include <vector>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        vector<int> diff(nums.size() + 1);
        int ans = 0, revCnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            revCnt += diff[i];
            if ((nums[i] + revCnt) % 2 == 0) {
                if (i + k > nums.size()) return -1;
                diff[i + k]--;
                revCnt++;
                ans++;
            }
        }
        return ans;
    }
};