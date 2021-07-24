#include <vector>
using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        bool flags[51];
        memset(flags, false, sizeof(flags));
        for (auto it = ranges.begin(); it != ranges.end(); it++) {
            fill(flags + *(*it).begin(), flags + *((*it).begin() + 1) + 1, true);
        }
        for (int i = left; i <= right; i++) {
            if (!flags[i]) return false;
        }
        return true;
    }
};

/*
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        bool flags[51];
        memset(flags, false, sizeof(flags));
        for (auto range : ranges) {
            fill(flags + range[0], flags + range[1] + 1, true);
        }
        for (int i = left; i <= right; i++) {
            if (!flags[i]) return false;
        }
        return true;
    }
};
*/