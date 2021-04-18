#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int getID(int x, long w) {
        return x < 0 ? (x + 1ll) / w - 1 : x / w;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int id = getID(nums[i], t + 1ll);
            if (mp.count(id)) return true;
            if (mp.count(id - 1) && abs(mp[id - 1] - (long)nums[i]) <= t) return true;
            if (mp.count(id + 1) && abs(mp[id + 1] - (long)nums[i]) <= t) return true;
            mp[id] = nums[i];
            if (i >= k) mp.erase(getID(nums[i - k], t + 1ll));
        }
        return false;
    }
};