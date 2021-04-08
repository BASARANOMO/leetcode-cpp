#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1) return nums[0] == target ? 0 : -1;
        int left = 0, right = n - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[0]) {
                if (nums[0] <= target && target <= nums[mid]) right = mid - 1;
                else left = mid + 1;
            } else {
                if (nums[mid] <= target && target <= nums[n - 1]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return -1;
    }
};