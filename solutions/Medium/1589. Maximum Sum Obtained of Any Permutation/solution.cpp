#include <vector>
using namespace std;

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        for (int i = 0; i < requests.size(); i++) {
            diff[requests[i][0]]++;
            diff[requests[i][1] + 1]--;
        }
        for (int i = 1; i < n + 1; i++) diff[i] += diff[i - 1];
        sort(diff.begin(), diff.end(), [](int a, int b) {return a > b;});
        sort(nums.begin(), nums.end(), [](int a, int b) {return a > b;});
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            if (diff[i] == 0) break;
            ans += (long long)nums[i] * diff[i];
        }
        return ans % int(1e9 + 7);
    }
};