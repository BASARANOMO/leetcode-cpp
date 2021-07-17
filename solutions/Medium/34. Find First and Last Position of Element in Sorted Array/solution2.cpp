#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool lower_bound) {
        int n = nums.size(), left = 0, right = n - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                if (lower_bound) right = mid - 1;
                else left = mid + 1;
            } else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return (lower_bound) ? left : right;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2);
        ans[0] = binarySearch(nums, target, true);
        ans[1] = binarySearch(nums, target, false);
        if (ans[0] > ans[1]) {
            ans[0] = -1, ans[1] = -1;
        }
        return ans;
    }
};