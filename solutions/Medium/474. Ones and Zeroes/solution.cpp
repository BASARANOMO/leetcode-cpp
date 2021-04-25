#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        vector<int> num_zeros(strs.size()), num_ones(strs.size());
        for (int i = 0; i < strs.size(); i++) {
            for (int j = 0; j < strs[i].size(); j++) num_ones[i] += strs[i][j] - '0';
            num_zeros[i] = strs[i].size() - num_ones[i];
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 0; k < strs.size(); k++) {
                    if (i >= num_zeros[k] && j >= num_ones[k]) dp[i][j] = max(dp[i][j], 1 + dp[i - num_zeros[k]][j - num_ones[k]]);
                }
            }
        }
        return dp[m][n];
    }
};