#include <vector>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;

    int checkRecord(int n) {
        vector<vector<long>> dp(2, vector<long>(3));
        dp[0][0] = 1;
        dp[1][0] = 1;
        dp[0][1] = 1;
        int temp1, temp2;
        for (int i = 1; i < n; i++) {
            temp1 = dp[0][0], temp2 = dp[1][0];
            dp[0][0] = (dp[0][0] + dp[0][1] + dp[0][2]) % MOD;
            dp[1][0] = (temp1 + dp[0][1] + dp[0][2] + dp[1][0] + dp[1][1] + dp[1][2]) % MOD;
            dp[0][2] = dp[0][1] % MOD;
            dp[0][1] = temp1 % MOD;
            dp[1][2] = dp[1][1] % MOD;
            dp[1][1] = temp2 % MOD;
        }
        return (dp[0][0] + dp[0][1] + dp[0][2] + dp[1][0] + dp[1][1] + dp[1][2]) % MOD;
    }
};