
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        set<long> s;
        for (int i = 0; i < n; i++) {
            auto iter = s.lower_bound((long)nums[i] - t);
            if (iter != s.end() && *iter <= (long)nums[i] + t) return true;
            s.insert(nums[i]);
            if (i >= k) s.erase(nums[i - k]);
        }
        return false;
    }
};