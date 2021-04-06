#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int curr = 2;
        while (curr < n) {
            if (nums[curr - 2] == nums[curr]) {
                n--;
                nums.erase(nums.begin() + curr, nums.begin() + curr + 1);
            } else {
                curr++;
            }
        }
        return n;
    }
};
