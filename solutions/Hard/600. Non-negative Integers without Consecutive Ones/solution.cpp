class Solution {
public:
    int findIntegers(int n) {
        vector<int> dp(31);
        dp[0] = dp[1] = 1;
        for (int i = 2; i < 31; i++) dp[i] = dp[i - 1] + dp[i - 2];
        int pre = 0, res = 0;
        for (int i = 29; i >= 0; i--) {
            int val = 1 << i;
            if ((n & val) != 0) { // if the right subtree exists
                res += dp[i + 1]; // number of paths in the left subtree (depth = i + 1)

                // treat the right subtree
                if (pre == 1) break; // 2 consecutive 1
                pre = 1; // the root val of the right subtree is 1
            } else pre = 0; // no right subtree, can not guarantee that the left subtree is a complete tree 
            if (i == 0) res++;
        }
        return res;
    }
};