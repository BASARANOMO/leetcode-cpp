#include <vector>
using namespace std;

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001);
        for (int i = 0; i < trips.size(); i++) {
            diff[trips[i][1]] += trips[i][0];
            diff[trips[i][2]] -= trips[i][0];
        }
        if (diff[0] > capacity) return false;
        for (int i = 1; i < diff.size(); i++) {
            diff[i] += diff[i - 1];
            if (diff[i] > capacity) return false;
        }
        return true;
    }
};