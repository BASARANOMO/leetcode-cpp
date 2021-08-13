#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        vector<unordered_map<long long, int>> f(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long diff = 1LL * nums[i] - nums[j];
                auto it = f[j].find(diff);
                int cnt = it == f[j].end() ? 0 : it->second;
                res += cnt;
                f[i][diff] += cnt + 1;
            }
        }
        return res;
    }
};
