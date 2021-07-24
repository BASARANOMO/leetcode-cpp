#include <vector>
using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52);
        for (auto range : ranges) {
            diff[range[0]]++;
            diff[range[1] + 1]--;
        }
        for (int i = 1; i < diff.size(); i++) diff[i] += diff[i - 1];
        for (int i = left; i <= right; i++) {
            if (diff[i] <= 0) return false;
        }
        return true;
    }
};