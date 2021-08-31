#include <vector>
using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> diff(101, 0);
        int ans = 1950;
        for (int i = 0; i < logs.size(); i++) {
            diff[logs[i][0] - ans] += 1;
            diff[logs[i][1] - ans] -= 1;
        }
        int val_max = diff[0];
        for (int i = 1; i < diff.size(); i++) {
            diff[i] += diff[i - 1];
            if (diff[i] > val_max) {
                val_max = diff[i];
                ans = 1950 + i;
            }     
        }
        return ans;
    }
};