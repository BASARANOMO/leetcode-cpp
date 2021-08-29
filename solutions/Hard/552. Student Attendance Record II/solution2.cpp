#include <vector>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;

    int checkRecord(int n) {
        vector<vector<vector<long>>> dp(n, vector<vector<long>>(2));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) dp[i][j].resize(3);
        }
        dp[0][0][0] = 1;
        dp[0][1][0] = 1;
        dp[0][0][1] = 1;
        for (int i = 1; i < n; i++) {
            dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;
            dp[i][0][1] = dp[i - 1][0][0] % MOD;
            dp[i][0][2] = dp[i - 1][0][1] % MOD;
            dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
            dp[i][1][1] = dp[i - 1][1][0] % MOD;
            dp[i][1][2] = dp[i - 1][1][1] % MOD;
        }
        return (dp[n - 1][0][0] + dp[n - 1][0][1] + dp[n - 1][0][2] + dp[n - 1][1][0] + dp[n - 1][1][1] + dp[n - 1][1][2]) % MOD;
    }
};