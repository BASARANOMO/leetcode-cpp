#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] && ++cnt == 3) return nums[i];
        }
        return nums[0];
    }
};