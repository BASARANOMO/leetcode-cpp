#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1, mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else { // nums[mid] == nums[right]
                right--;
            }
        }
        return nums[left];
    }
};