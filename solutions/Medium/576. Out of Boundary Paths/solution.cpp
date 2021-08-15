#include <vector>
using namespace std;

class Solution {
public:
    static constexpr int MOD = 1000000007;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int res = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        dp[startRow][startColumn] = 1;
        for (int i = 0; i < maxMove; i++) {
            vector<vector<int>> dp_new(m, vector<int>(n));
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    int cnt = dp[j][k];
                    if (cnt > 0) {
                        for (auto &dir : directions) {
                            int j_next = j + dir[0], k_next = k + dir[1];
                            if (j_next >= 0 && j_next < m && k_next >= 0 && k_next < n) {
                                dp_new[j_next][k_next] = (dp_new[j_next][k_next] + cnt) % MOD;
                            } else {
                                res = (res + cnt) % MOD;
                            }
                        }
                    }
                }
            }
            dp = dp_new;
        }
        return res;
    }
};