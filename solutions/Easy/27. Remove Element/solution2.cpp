#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            if (nums[left] == val) {
                nums[left] = nums[right--];
            } else left++;
        }
        return left;
    }
};
