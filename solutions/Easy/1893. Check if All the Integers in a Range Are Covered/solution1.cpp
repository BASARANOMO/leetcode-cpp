#include <vector>
using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end(), [](const vector<int>& a, const vector<int>& b) { return a[0] < b[0]; });
        for (auto range : ranges) {
            if (left <= range[1] && left >= range[0]) left = range[1] + 1;
        }
        return left > right;
    }
};