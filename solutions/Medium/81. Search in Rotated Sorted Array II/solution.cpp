#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1) return nums[0] == target ? true : false;
        int left = 0, right = n - 1, mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) return true;
            if (nums[mid] == nums[left] && nums[mid] == nums[right]) {
                left++;
                right--;
            }
            else if (nums[mid] >= nums[left]) {
                if (nums[left] <= target && target <= nums[mid]) right = mid - 1;
                else left = mid + 1;
            } else {
                if (nums[mid] <= target && target <= nums[right]) left = mid + 1;
                else right = mid - 1;
            }
        }
        return false;
    }
};