#include <vector>
using namespace std;

class Solution {
public:
    int MOD = 1e9 + 7;
    int dfs(int n, int day, int absent_cnt, int consequent_late_cnt, vector<vector<vector<int>>>& memo) {
        if (day == n) return 1;
        if (memo[day][absent_cnt][consequent_late_cnt]) return memo[day][absent_cnt][consequent_late_cnt];
        int ans = 0;
        if (absent_cnt < 1) {
            ans = (ans + dfs(n, day + 1, 1, 0, memo)) % MOD;
        }
        if (consequent_late_cnt < 2) {
            ans = (ans + dfs(n, day + 1, absent_cnt, consequent_late_cnt + 1, memo)) % MOD;
        }
        ans = (ans + dfs(n, day + 1, absent_cnt, 0, memo)) % MOD;
        memo[day][absent_cnt][consequent_late_cnt] = ans;
        return ans;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(2));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) memo[i][j].resize(3);
        }
        return dfs(n, 0, 0, 0, memo);
    }
};