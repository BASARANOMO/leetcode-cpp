#include <vector>
using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        bool flags[51];
        memset(flags, false, sizeof(flags));
        int l, r;
        for (auto range : ranges) {
            l = max(left, range[0]);
            r = min(right, range[1]);
            if (l <= r) fill(flags + l, flags + r + 1, true);
        }
        for (int i = left; i <= right; i++) {
            if (!flags[i]) return false;
        }
        return true;
    }
};