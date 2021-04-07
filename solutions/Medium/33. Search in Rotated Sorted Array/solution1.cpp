#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1) return nums[0] == target ? 0 : -1;
        int left = 0, right = n - 1, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] < nums[right]) right = mid;
            else left = mid + 1;
        }
        // min element: nums[left]
        if (left == 0) {
            // only 1 section
            right = n - 1;
        } else {
            if (nums[0] > target) {
                right = n - 1;
            } else {
                right = left - 1;
                left = 0;
            }
        }
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};