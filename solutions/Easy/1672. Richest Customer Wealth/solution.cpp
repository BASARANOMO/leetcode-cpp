class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0, curr = 0;
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 0; j < accounts[0].size(); j++) curr += accounts[i][j];
            ans = ans > curr ? ans : curr;
            curr = 0;
        }
        return ans;
    }
};